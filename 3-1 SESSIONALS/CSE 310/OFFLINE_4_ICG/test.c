int a,b,c;

int bar(int a, int b){	
	c = 4*a + 2*b;
	return c;
}

int main(){

	int i,j,k,l;
	
	i = 5;
	j = 6;
	
	l = bar(i,j);
	println(l);
	
	

    return 0;
}