/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicoara <inicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:25:39 by inicoara          #+#    #+#             */
/*   Updated: 2025/09/30 16:26:43 by inicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct
{
	double x;
    double y;
}	Vec2;

typedef struct
{ /* Boîte axis-aligned d'une cellule mur */
	double x0;
    double y0;
    double x1;
    double y1;
}	AABB;

typedef struct
{ /* Bornes des cellules à inspecter */
	int min_mx;
    int max_mx;
	int min_my;
    int max_my;
}	GridBounds;

typedef struct
{ /* Point le plus proche sur l'AABB */
	double nx;
    double ny;
}	ClosestPoint;

typedef struct
{                  /* Données de chevauchement/pénétration */
	double vx;
    double vy; /* vecteur centre -> point le + proche */
	double d2;     /* distance^2 centre ↔ point le + proche */
	double r2;     /* rayon^2 */
}	Penetration;

#endif