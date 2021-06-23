
void npc(){
    int aleatorio_npc;
    //Para sortear a fala do NPC
    aleatorio_npc = rand()%4;

    switch (aleatorio_npc)
    {
    case 0:
        printf("||| Joao diz:\n");
        printf("            Fiquei sabendo que ao norte existe varios tesouros caros..\n\n");
        printf("                                        Pressione qualque tecla..");
        break;
    case 1:
        printf("Caro amigo esse e o 1");
        break;
    case 2:
        printf("Vejo que voce esta muito cansado toma aqui essa poção...\n");
        break;
    case 3:
        printf("caro amigo 3\n");
        break;
    case 4:
        printf("AMIGO E O 4");
        break;
    }
system("pause");
}

