// #include <stdio.h>
//



int
main(){
	while(1){
		volatile int i = 42;
		if (i == 42)
			i++;
	}
}
