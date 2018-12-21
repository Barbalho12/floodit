-| FUNCIONALIDADE IMPLEMENTADAS |-

	1. Criação de typedef, structs e enuns.
	2. Modularização do programa (arquivos .c e .h). 
	3. Geração aleatória do tabuleiro (14x14 células); 
	4. Apresentação da interface inicial do jogo com o tabuleiro gerado. 
	5. Leitura da entrada do usuário.
	6. Atualização do tabuleiro de forma recursiva.
	7. Preenchendo os adjacentes de mesma cor.
	8. Implementação da condição de término do jogo (máximo 25 rodadas ou tabuleiro completamente preenchido).
	9. Salvamento e carregamento do estado de um jogo.
	10. Elementos extras:
		10.1 Distribuição uniforme na geração das cores no tabuleiro.
		10.2 Desenvolvimento de Interface Gráfica compatível com Linux e Windows.
		10.3 Comunicação com o usuário atrvés do click do mouse.
		10.4 Possibilitar a criação de partidas com outros níveis de dificuldades com tabuleiros maiores/menores e número máximos de jogadas.
		
	11. Documentação de funcionalidades de cada subrotina.

	
-| NÃO FOI IMPLEMENTADO |-
	
	1. Dar a possibilidade de Salvar e Carregar vários jogos.
	2. Possibilitar a criação de partidas com quantidade de cores diferentes.

	
-| REFLEXÃO |-

	O feito mais importante durante o desenvolvimento do jogo foi a padronização do código, buscando sempre modularizar
	cada funcionalidade de forma que o mesmo tivesse um modelo coeso de organização, facilitando a manutenção e a inserção de novas
	funcionalidades. E a impressão que fica é que poderiamos aprimorar ainda mais essa padronização, tornando o código mais abstrato e 
	mais simples de ser compreendido.


-| COMPILAÇÃO |-

	-|Windows|-

		Biblioteca Gráfica: GTK 
		Versão: 3.6.4
		Download: http://www.gtk.org/download/win32.php
		Instalação: http://www.gtk.org/download/win32_tutorial.php

		Compilação loadGame (main):
			gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame -mms-bitfields 
			-IC:/gtk3/include/gtk-3.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 
			-IC:/gtk3/include/cairo -IC:/gtk3/include -IC:/gtk3/include/gdk-pixbuf-2.0 -IC:/gtk3/include/libpng15 
			-IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgobject-2.0 -lglib-2.0

		Compilação newGame (main):
			gcc newGame.c color.c table.c file.c -o newGame

	-|Linux|-
		
		Biblioteca Gráfica: GTK 
		Versão: 3.12
		Download: http://www.gtk.org/download/linux.php ou através do comando: "sudo apt-get install libgtk-3-dev"
		Instalação: https://developer.gnome.org/gtk3/stable/gtk-building.html
		
		loadGame (main):
			gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame `pkg-config --cflags --libs gtk+-3.0`

		newGame (main):
			gcc newGame.c color.c table.c file.c -o newGame



-| COMPONENTES |-
	Felipe Barbalho Rocha 
	Raul Silveira Silva
	
	- | TAREFAS INDIVIDUAIS | -
		Todo o desenvolvimento do jogo foi realizado em conjunto, sem divisão de tarefas. sendo possivel uma visão mais completa de ambos os componentes
		sobre o projeto como um todo, e um maior complemento de ideias.

