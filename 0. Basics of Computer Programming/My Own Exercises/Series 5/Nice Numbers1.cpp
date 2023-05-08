#include <iostream>
#include <cmath>

using namespace std;

bool isItJolly( int diff[], int n ) {
	for ( int i = 0; i < n - 1; i++ ) {
		if ( diff[ i ] == 0 || diff[ i ] >= n )
			return false;
	}
	return true;
}
int main() {
	int n, num[3000], i = 0, difference[3000];
	while ( cin ) {
		cin >> n;
		while ( i < n ) {
			cin >> num[ i ];
			i++;
		}
		for ( int j = 1; j < n; j++ ) 
			difference[ j - 1 ] = fabs( num[ j - 1 ] - num[ j ] );
			
		if ( isItJolly( difference, n ) )
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}