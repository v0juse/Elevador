//This file was generated from (Academic) UPPAAL 4.1.25-5 (rev. 643E9477AA51E17F), April 2021

/*

*/
A[] not deadlock

/*

*/
A[] movimento == 1 imply not portaAberta

/*

*/
A[] numPessoasDentro <= 4

/*

*/
E<>joo.Escolhendo_Novo_Destino

/*

*/
joo.Dentro_do_Elevador --> joo.Fora_do_Elevador

/*

*/
E<>(joo.andarDestinoUsuario == andarAtual)

/*

*/
A[] not(portas.Fechada and objetoBloqueante)
