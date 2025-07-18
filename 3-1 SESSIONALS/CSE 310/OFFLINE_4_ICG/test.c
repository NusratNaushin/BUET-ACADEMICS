int a,b,c;

int foo(int a){
	a = a + 3;
	return a;
}

int main(){

	int i,j,k,l;
	
	i = 5;
	j = 6;
	k = foo(i);
	println(k);
    return 0;
}