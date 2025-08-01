 

//search for all the words 

int is_garbage(int argc, char *argv[], char *env[])
{
    char *words[10];

    words[0] = "NO";
    words[1] = "SO";
    words[2] = "WE";
    words[3] = "EA";
    words[4] = "C";
    words[5] = "F";
    words[6] = "N";
    words[7] = "E";
    words[8] = "S";
    words[9] = "W";
    words[10] = "1";
    words[11] = "0";
    words[12] = " ";

    /* 
        -- le pb de is_garbage c que je dois verifier si ya pas
        de character non voulue ...
        -- le probleme est aussi que poour les assets je peux avoir 
        ./ ou un path
        -- et que pour le path je peux verifier que par rapport a leur debut / ou ./
        --


        -- on va dire que si une ligne a des 111111111 c le debut de la map...
        -- est ce que ce serait pas mal d'essayer de faire un regexer ... 
    */  
}