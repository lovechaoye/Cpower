target=main
dependency=main.c

$(target):$(dependency)
	gcc -O0 -save-temps $^ -o $@

clean:
	rm -rf *.i *.s *.o $(target)
