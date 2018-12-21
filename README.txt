-| FUNCIONALIDADE IMPLEMENTADAS |-

	1. Cria��o de typedef, structs e enuns.
	2. Modulariza��o do programa (arquivos .c e .h). 
	3. Gera��o aleat�ria do tabuleiro (14x14 c�lulas); 
	4. Apresenta��o da interface inicial do jogo com o tabuleiro gerado. 
	5. Leitura da entrada do usu�rio.
	6. Atualiza��o do tabuleiro de forma recursiva.
	7. Preenchendo os adjacentes de mesma cor.
	8. Implementa��o da condi��o de t�rmino do jogo (m�ximo 25 rodadas ou tabuleiro completamente preenchido).
	9. Salvamento e carregamento do estado de um jogo.
	10. Elementos extras:
		10.1 Distribui��o uniforme na gera��o das cores no tabuleiro.
		10.2 Desenvolvimento de Interface Gr�fica compat�vel com Linux e Windows.
		10.3 Comunica��o com o usu�rio atrv�s do click do mouse.
		10.4 Possibilitar a cria��o de partidas com outros n�veis de dificuldades com tabuleiros maiores/menores e n�mero m�ximos de jogadas.
		
	11. Documenta��o de funcionalidades de cada subrotina.

	
-| N�O FOI IMPLEMENTADO |-
	
	1. Dar a possibilidade de Salvar e Carregar v�rios jogos.
	2. Possibilitar a cria��o de partidas com quantidade de cores diferentes.

	
-| REFLEX�O |-

	O feito mais importante durante o desenvolvimento do jogo foi a padroniza��o do c�digo, buscando sempre modularizar
	cada funcionalidade de forma que o mesmo tivesse um modelo coeso de organiza��o, facilitando a manuten��o e a inser��o de novas
	funcionalidades. E a impress�o que fica � que poderiamos aprimorar ainda mais essa padroniza��o, tornando o c�digo mais abstrato e 
	mais simples de ser compreendido.


-| COMPILA��O |-

	-|Windows|-

		Biblioteca Gr�fica: GTK 
		Vers�o: 3.6.4
		Download: http://www.gtk.org/download/win32.php
		Instala��o: http://www.gtk.org/download/win32_tutorial.php

		Compila��o loadGame (main):
			gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame -mms-bitfields 
			-IC:/gtk3/include/gtk-3.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 
			-IC:/gtk3/include/cairo -IC:/gtk3/include -IC:/gtk3/include/gdk-pixbuf-2.0 -IC:/gtk3/include/libpng15 
			-IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgobject-2.0 -lglib-2.0

		Compila��o newGame (main):
			gcc newGame.c color.c table.c file.c -o newGame

	-|Linux|-
		
		Biblioteca Gr�fica: GTK 
		Vers�o: 3.12
		Download: http://www.gtk.org/download/linux.php ou atrav�s do comando: "sudo apt-get install libgtk-3-dev"
		Instala��o: https://developer.gnome.org/gtk3/stable/gtk-building.html
		
		loadGame (main):
			gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame `pkg-config --cflags --libs gtk+-3.0`

		newGame (main):
			gcc newGame.c color.c table.c file.c -o newGame



-| COMPONENTES |-
	Felipe Barbalho Rocha 
	Raul Silveira Silva
	
	- | TAREFAS INDIVIDUAIS | -
		Todo o desenvolvimento do jogo foi realizado em conjunto, sem divis�o de tarefas. sendo possivel uma vis�o mais completa de ambos os componentes
		sobre o projeto como um todo, e um maior complemento de ideias.

