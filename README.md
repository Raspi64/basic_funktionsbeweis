# --- Fabian README ---

## Installation

### Clone repo
	$ make clean
	$ git clone https://github.com/Raspi64/basic_funktionsbeweis
	$ cd basic_funktionsbeweis

### Compile
	$ make

### Launch
	$ ./cbmbasic

-----------------------

## How to Create/Use a basic script

### Create a script
	$ touch script.bas
	$ chmod +x scipt.bas

### Example script code
The first line has to be the Path to your cbmbasic for example *#!/usr/bin/cbmbasic*
You can also use cbmbasic as a UNIX scripting language by adding a hashbang line to your BASIC program and making it executable.

	#!/usr/bin/cbmbasic 
	10 OPEN 1,1,1,"TEST.DAT"
	20 PRINT#1, 1234
	30 PRINT#1, "Hello"
	40 CLOSE 1

	50 OPEN 2,1,0,"TEST.DAT"
	60 INPUT#2, A
	70 INPUT#2, I$
	80 CLOSE 2

	90 PRINT A
	100 PRINT I$
	RUN

### How to run the script
	$ ./script.bas

-----------------------


##  Code expansion
For code expansion you need to edit the plugin.c file.
In the marked area you first define an instruction name.
The Last line has to be a continue.

	if (compare("INSTRUCTION")){
		//code
		continue;
	}

To get the parameter you can use these funktion:

	get_word()
	get_byte()
	get_string(char *s)
	
If parameters had to be separate with a comma:	

	check_comma()

-----------------------

## List of implemented commands
	PRINT
	PRINT#
	INPUT
	INPUT#
	OPEN
	LOAD
	SAVE
	NEW
	CONT
	REM
	STOP
	END
	RUN
	LIST
	^
	*
	/
	+
	-
	=
	<
	>
	<=
	>=
	<>
	IF
	THEN
	REM
	FOR
	TO
	GOTO
	NEXT
	TOSQR
	POS
	SPC
	TAB
	RND
	(CHR$)
	(MOD falsches ergebnis)
	
-----------------------

## Exercises
Aufgabe 1: Hello World!
Schreibe ein kleines Programm das den String “Hello World!” einmal ausgibt.

Musterlösung:


	10 PRINT “Hello World!”
	20 END
	RUN



Aufgabe 2: Hello World! To everyone
Schreib ein kleines Programm das den String “Hello World!” unendlich oft ausgibt.

Musterlösung:


	10 PRINT "Hello World!"
	20 GOTO 10
	30 END
	RUN


Aufgabe 3: Der Countdown
Schreibe ein Programm das die Zahlen von 10 bis einschließlich 0 ausgibt.

Musterlösung:


	10 FOR I = 0 TO 10 STEP 1
	20 PRINT 10-I
	30 NEXT
	40 END
	RUN


Aufgabe 4: The numbers every programmer must know
Schreibe ein Programm das die Exponenten von 2^n bis einschließlich 1024 ausgibt.

Musterlösung:


	10 FOR I = 0 TO 10 STEP 1
	20 PRINT 2^I
	30 NEXT
	40 END
	RUN


Aufgabe 5: Gauß the brain
Schreib ein Programm das die Summe von 1 bis n (z.B. 100) errechnet. Die Zahll n soll im Verlauf des Programms variabel eingegeben werden können.

Musterlösung:


	10 PRINT "Gib die höchste Zahl ein:"
	10 INPUT A
	20 PRINT (A*(A+1))/2
	30 END
	RUN

# --- cbmbasic README---


# cbmbasic - Commodore BASIC V2 as a scripting language

"Commodore BASIC" (cbmbasic) is a 100% compatible version of Commodore's version of Microsoft BASIC 6502 as found on the Commodore 64. You can use it in interactive mode or pass a BASIC file as a command line parameter.

This source does not emulate 6502 code; all code is completely native. On a 1 GHz CPU you get about 1000x speed compared to a 1 MHz 6502.

## Compatibility

It has been tested with

* Mac OS X 10.4/10.5 i386/x86_64/ppc (GCC 3.3/4.0)
* Debian Linux Etch (GCC 3.3/4.1)
* Windows NT (Visual Studio 2005/2008)

Other CPUs, operating systems and compilers should work, too.

Windows users should also install the [Microsoft Visual C++ 2005 SP1 Redistributable Package (x86)]("http://www.microsoft.com/downloads/details.aspx?familyid=200b2fd9-ae1a-4a14-984d-389c36f85647&displaylang=en").

## Usage
You can use cbmbasic in interactive mode by just running the binary without parameters, or you can specify an ASCII-encoded BASIC program on the command line. You can also use cbmbasic as a UNIX scripting language by adding a hashbang line to your BASIC program and making it executable.

    $ ls -l hello.bas 
    -rwxr-xr-x  1 mist  staff  40  7 Apr 21:30 hello.bas
    $ cat hello.bas 
    #!/usr/bin/cbmbasic
    PRINT"HELLO WORLD!"
    $ ./hello.bas 
    HELLO WORLD!

cbmbasic implements a small plugin system that lets developers add additional statements, functions etc. Right now, you can turn this on with "SYS 1" (turn off with "SYS 0"), and use the new statements LOCATE *y*, *x* (set cursor position), SYSTEM *string* (run command line command) and the extended WAIT *port*, *mask*, which implements the [Bill Gates easter egg](http://www.pagetable.com/?p=43).

## Internals
The core of the BASIC interpreter is in the file `cbmbasic.c`, which is platform, endianness and bitness independent. For all I/O, it calls out into `runtime.c`, so it should be possible to adapt this project for any OS by just changing `runtime.c`.

All function calls that the core interpreter can't handle end up in kernal_dispatch() in `runtime.c`, where a switch statement dispatches these to C functions. For Commodore BASIC, `runtime.c` has to support several Commodore KERNAL library routines. Some of them are very important (CHRIN, CHROUT) and some are only used for certain BASIC statements (LOAD, SAVE, OPEN, SETTIM). `runtime.c` does not implement all functions yet.

## License
Feel free to use this project for any purpose, give credit if you like, and send back improvements to the authors, if you like, so that others can benefit from it. See source for license details.

## Contact
[Michael Steil](mailto:mist@c64.org), [James Abbatiello](mailto:abbeyj@gmail.com)
