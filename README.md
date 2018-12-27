# Flood-It

## Funcionalidades

- [X] Criação de typedef, structs e enuns.
- [X] Modularização do programa (arquivos .c e .h). 
- [X] Geração aleatória do tabuleiro (14x14 células); 
- [X] Apresentação da interface inicial do jogo com o tabuleiro gerado. 
- [X] Leitura da entrada do usuário.
- [X] Atualização do tabuleiro de forma recursiva.
- [X] Preenchendo os adjacentes de mesma cor.
- [X] Implementação da condição de término do jogo (máximo 25 rodadas ou tabuleiro completamente preenchido).
- [X] Salvamento e carregamento do estado de um jogo.
- [X] Distribuição uniforme na geração das cores no tabuleiro.
- [X] Desenvolvimento de Interface Gráfica compatível com Linux e Windows.
- [X] Comunicação com o usuário atrvés do click do mouse.
- [X] Possibilitar a criação de partidas com outros níveis de dificuldades com tabuleiros maiores/menores e número máximos de jogadas.	
- [X] Documentação de funcionalidades de cada subrotina.
	
- [ ] Dar a possibilidade de Salvar e Carregar vários jogos.
- [ ] Possibilitar a criação de partidas com quantidade de cores diferentes.

## Compilação 

### Windows

* Biblioteca Gráfica: GTK 
* Versão: 3.6.4
* Download: http://www.gtk.org/download/win32.php
* Instalação: http://www.gtk.org/download/win32_tutorial.php

```bash
# Compilação loadGame
gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame -mms-bitfields 
-IC:/gtk3/include/gtk-3.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 
-IC:/gtk3/include/cairo -IC:/gtk3/include -IC:/gtk3/include/gdk-pixbuf-2.0 -IC:/gtk3/include/libpng15 
-IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgobject-2.0 -lglib-2.0
# Compilação newGame
gcc newGame.c color.c table.c file.c -o newGame
```

### Linux

* Biblioteca Gráfica: GTK 
* Versão: 3.12
* Download: http://www.gtk.org/download/linux.php ou através do comando: "sudo apt-get install libgtk-3-dev"
* Instalação: https://developer.gnome.org/gtk3/stable/gtk-building.html

```bash
# Compilação loadGame
gcc loadGame.c interface.c color.c table.c file.c controle.c -o loadGame `pkg-config --cflags --libs gtk+-3.0`
# Compilação newGame
gcc newGame.c color.c table.c file.c -o newGame
```


## Componentes 

Felipe Barbalho Rocha 
Raul Silveira Silva

