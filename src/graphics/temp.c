
static inline int tile_x(double x) { return (int)floor(x); }
static inline int tile_y(double y) { return (int)floor(y); }

static inline int is_open_cell(t_game *g, int my, int mx)
{
    if (my < 0 || mx < 0)
		return 0;
    if (my >= g->map_height || mx >= g->map_width) return 0;
    return g->world_map[my][mx] == '0';
}


static inline double clampd(double v, double a, double b) {
    return (v < a) ? a : (v > b) ? b : v;
}

static inline int inside_map(const t_game *g, int my, int mx) {
    return (my >= 0 && my < g->map_height && mx >= 0 && mx < g->map_width);
}

/* Repousse le centre (g->pos_x, g->pos_y) en dehors des murs si le cercle (rayon)
   chevauche une case solide. Gère bien les coins. */
static void fix_position_near_walls(t_game *g, double radius)
{
    double cx = g->pos_x;
    double cy = g->pos_y;
    const double eps = 1e-6;

    /* Quelques itérations au cas où le centre chevauche plusieurs cases (coins) */
    for (int iter = 0; iter < 3; ++iter) {
        int changed = 0;

        int min_mx = (int)floor(cx - radius) - 1;
        int max_mx = (int)floor(cx + radius) + 1;
        int min_my = (int)floor(cy - radius) - 1;
        int max_my = (int)floor(cy + radius) + 1;

        for (int my = min_my; my <= max_my; ++my) {
            for (int mx = min_mx; mx <= max_mx; ++mx) {
                if (!inside_map(g, my, mx)) continue;
                if (is_open_cell(g, my, mx)) continue; // on ne traite que les murs

                /* AABB de la case mur */
                double bx0 = mx,     by0 = my;
                double bx1 = mx + 1, by1 = my + 1;

                /* Point le plus proche de l’AABB */
                double nx = clampd(cx, bx0, bx1);
                double ny = clampd(cy, by0, by1);

                double vx = cx - nx;
                double vy = cy - ny;
                double d2 = vx*vx + vy*vy;
                double r2 = radius * radius;

                if (d2 < r2 - 1e-12) {
                    /* Il y a chevauchement */
                    if (d2 > eps*eps) {
                        double d = sqrt(d2);
                        double push = (radius - d);
                        cx += (vx / d) * push;
                        cy += (vy / d) * push;
                    } else {
                        /* Cas dégénéré (centre sur l'arête/coin) :
                           on pousse le long de l’axe le plus “proche” du centre de la box */
                        double bcx = 0.5 * (bx0 + bx1);
                        double bcy = 0.5 * (by0 + by1);
                        double ax = fabs(cx - bcx);
                        double ay = fabs(cy - bcy);

                        if (ax > ay) {
                            /* repousser en X jusqu’à être à radius de la face */
                            if (cx > bcx) cx = bx1 + radius + eps;
                            else          cx = bx0 - radius - eps;
                        } else {
                            /* repousser en Y */
                            if (cy > bcy) cy = by1 + radius + eps;
                            else          cy = by0 - radius - eps;
                        }
                    }
                    changed = 1;
                }
            }
        }
        if (!changed) break; // plus d’overlap
    }

    g->pos_x = cx;
    g->pos_y = cy;
}

// Test de déplacement avec "rayon" pour éviter de s'accrocher aux coins.
// dx/dy = vecteur de déplacement (nouvelle position - ancienne position)
static void try_move_with_radius(t_game *g, double new_x, double new_y,
                                 double dx, double dy, double radius)
{
    double off_x = (dx > 0.0) ? radius : (dx < 0.0 ? -radius : 0.0);
    double off_y = (dy > 0.0) ? radius : (dy < 0.0 ? -radius : 0.0);

    // Test axe X
    int test_mx = tile_x(new_x + off_x);
    int cur_my  = tile_y(g->pos_y);
    if (is_open_cell(g, cur_my, test_mx))
        g->pos_x = new_x;

    // Test axe Y (en utilisant pos_x possiblement mis à jour pour permettre le "sliding")
    int test_my = tile_y(new_y + off_y);
    int cur_mx  = tile_x(g->pos_x);
    if (is_open_cell(g, test_my, cur_mx))
        g->pos_y = new_y;
    
    fix_position_near_walls(g, radius);
}

int handle_movement(t_ctx *ctx)
{
    t_mlx  *m = ctx->mlx;
    t_game *g = ctx->game;

    // Utilise les vitesses du jeu si elles sont renseignées, sinon des défauts
    double move_speed = (g->move_speed     > 0.0) ? g->move_speed     : 0.05;
    double rot_speed  = (g->rotation_speed > 0.0) ? g->rotation_speed : 0.05;
    double radius = 0.25;

    double old_dir_x, old_plane_x;

    // --- Avancer (W)
    if (m->w) {
        double dx = g->dir_x * move_speed;
        double dy = g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Reculer (S)
    if (m->s) {
        double dx = -g->dir_x * move_speed;
        double dy = -g->dir_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe gauche (A) : utilise le plan (perpendiculaire à dir)
    if (m->a) {
        double dx = -g->plane_x * move_speed;
        double dy = -g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Strafe droit (D)
    if (m->d) {
        double dx =  g->plane_x * move_speed;
        double dy =  g->plane_y * move_speed;
        try_move_with_radius(g, g->pos_x + dx, g->pos_y + dy, dx, dy, radius);
    }

    // --- Rotation
    if (m->left_arrow || m->right_arrow) {
        double angle = m->left_arrow ? -rot_speed : rot_speed;

        old_dir_x   = g->dir_x;
        g->dir_x    = g->dir_x * cos(angle) - g->dir_y * sin(angle);
        g->dir_y    = old_dir_x * sin(angle) + g->dir_y * cos(angle);

        old_plane_x = g->plane_x;
        g->plane_x  = g->plane_x * cos(angle) - g->plane_y * sin(angle);
        g->plane_y  = old_plane_x * sin(angle) + g->plane_y * cos(angle);
    }

    return 0;
}


