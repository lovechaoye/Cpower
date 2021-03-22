target=bit_field
dependency=$(target).c
$(target):$(dependency)
	gcc -save-temps -O0 $^ -o $@
clean:
	rm -rf *.s *.o *.i $(target)
