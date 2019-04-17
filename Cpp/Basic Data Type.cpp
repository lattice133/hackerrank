# include "iostream"

using namespace std

int main(){
	
	int var1; long var2; char var3; float var4; double var5;
	
	cin >> var1 >> var2 >> var3 >> var4 >> var5;
	
	cout << var1 << endl << var2 << endl << var3 << endl;
	cout.precision(3);
	cout << fixed << var4 << endl;
	cout.precision(9);
	cout << fixed << var5 << endl; 
	
}
