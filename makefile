main.o:
	make -C ./ModuleA/
	make -C ./ModuleB/
	make -C ./ModuleC/
	export LD_LIBRARY_PATH=./RELEASE
	gcc main.c -I./Include -L./RELEASE -lSTUOP -lLESOP -lINPR -o app

