#include <iostream>
#include <string>
#include <string.h>
//#include <juego.h>


using namespace std;

char** crearmatriz();
void imprimir(char**);
void freemat(char**);
void llenar(char**);
bool puedemover(int,int,char,char**,int,int,int,int);
bool piezacorrecta(int,int,char,char**&);
void comer(int,int,char,char**&);
bool vivo(char,char**);
int main(){
	int resp=0;
	do{
	cout<<"1) Jugar"<<endl
		<<"2) Salir"<<endl
		<<"Escoja su opcion: ";
	cin >>resp;

	}while(resp<1||resp>2);	
	char** tablero;
	tablero= crearmatriz();
	llenar(tablero);
	tablero[6][1]='#';
	tablero[6][11]='#';
	tablero[1][6]='+';
	tablero[11][6]='+';
	
	int termino=4;
	//freemat(tablero);
	char turno='+';

	 bool mov_valido=false;
	bool pieza=false;
	char posj;
	//cout<<tablero[1][6]<<endl;
	// ni == nuwva posiicon en i y nj == nueva posicion en j
	int posi,pj,ni,nj,suma_i,suma_j;
	bool vive;
	do{
		vive=vivo(turno,tablero);
		cout<<vive<<endl;
		if(vive==true){
		mov_valido=false;
		imprimir(tablero);
		cout<<endl;
		cout<<"Mueven las Piezas: "<<turno<< " !!"<<endl;
			do{
				cout<<"Ingrese Posicion de I [1-11]: ";
				cin >>posi;
				cout<<"Ingrese Posicion de J[1-11]: ";
				cin >>pj;
					
				pieza=piezacorrecta(posi,pj,turno,tablero);
							
			}while(pieza==false);
	//DO QUE VALIDA LA NUEVA POSICION SI SE REPITE
		do{
			do{	
				//DO QUE VALIDA QUE NO SE PASE DE LOS LIMITES DE I
				do{
					cout<<"Ingrese la nueva posicion en I[1-11]: ";
					cin>>ni;
				}while(ni<1||ni>11);
				//DO QUE VALIDA QUE NO SE PASE DE LOS LIMITES DE J
				do{
					cout<<"Ingrese la nueva posicion en J[1-11]: ";
					cin >>nj;	
				}while(nj<1||nj>11);
			}while(ni==posi && nj==pj);
				suma_i=posi-ni;
				suma_j=pj-nj;
				if(suma_i<0){
					suma_i*=-1;
//					cout<<"Es menor"<<endl;
				}
				if(suma_j<0){
					suma_j*=-1;
				}	
		//	cout<<"------"<<suma_i<<"----- "<<suma_j<<"-----------"<<endl;
			if( (suma_i==2 ||suma_i==1|| suma_i==0)&&(suma_j==1||suma_j==2||suma_j==0 ) ){
		//cout<<"Si se puede"<<endl;
		mov_valido=puedemover(ni,nj,turno,tablero,suma_j,suma_i,posi,pj);

			}else{
			cout<<"Movimiento Invalido intente de Nuevo" <<endl;	
			mov_valido=false;
			}	
		//	mov_valido=puedemover( );
		}while(mov_valido==false);	
		comer(ni,nj,turno,tablero);
		if(turno=='+'){
			turno='#';
		}else{
			turno='+';
		}	
		cout<<pieza<<endl;
	}else{
			if(turno=='#'){
				cout<<"JUGADOR 1 GANA"<<endl;
			}else{
				cout<<"JUGADOR 2 GANA"<<endl;
			}
		
		}
		
	}while(vive==true);	
	freemat(tablero);		
return 0;
}	

char**crearmatriz(){
	char** mat=new char*[12];
	for (int i=0;i<12;i++){
	mat[i]=new char[12];
	}	
return mat;
}	
void freemat(char** mat){
	for (int i=0;i<12;i++){
	delete[] mat[i];
	mat[i]=NULL;
	}	
	delete[] mat; 
}


void imprimir(char** mat){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++)	{
			//IF que hacen la fila de numeros en J
			if(j==0){
				if(i<10){
					cout<<" "<<i;
				}else{
					cout<<i;
				}
				
			}else if(i==0){
				cout<<" "<<j;
			/*
				switch(j){
					
					case 1:
						cout<< " A";
						break;
					case 2:
						cout<< " B";
						break;
					case 3: 
						cout<<" C";	
						break;
					case 4: 
						cout<<" D";
						break;
					case 5: 
						cout<<" E";
						break;
					case 6: 
						cout<<" F";
						break;
					case 7:
						cout<<" G";
						break;
					case 8:
						cout<<" H";
						break;
					case 9:
						cout<<" I";
						break;
					case 10:
						cout<<" J";
						break;
					case 11:
						cout<<" K";
						break;	
				}	
			*/		
			}else{	
			cout<<" "<<mat[i][j];
			}
		}	
		cout<<endl;
	}	
}

void llenar(char** mat){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			mat[i][j]='0';
		}	
	}	


}
bool piezacorrecta(int i,int  j,char pieza,char**& mat){
	bool valido=false;
	/*
	switch (j1){
		case 'A':
			j=1;
		cout<<"Entro!!!! "<<j<<endl;
			break;
		case 'B':
			j=2;
			break;
	}
	*/
	
	//cout<<pieza <<"        HMMMMMMMMM   "<<mat[i][j]<<endl;	
	if(mat[i][j]==pieza) {
        valido=true;
		//cout<<"Verdadero!"<<endl;
	}else{
		//cout<<"Falso!"<<endl;

	}	
return valido;
}
bool puedemover(int newi,int newj,char pieza,char** mat,int saltoj,int saltoi,int i,int j){
	bool valido=false;
	if(mat[newi][newj]=='0'){
		if(saltoi==2 ||saltoj==2){				
			mat[i][j]='0';

		}
			mat[newi][newj]=pieza;	
		valido=true;	
	}	

return valido;


}
void comer(int i,int j,char pieza,char**& mat){
	if(pieza=='+'){
		if((i-1>0) && (j-1>0) ){
			if(mat[i-1][j-1]=='#' ){
				mat[i-1][j-1]='+';
			}	
		}
		
			if(j-1>0){
		//		cout<<"Entro???"<<endl;
				if(mat[i][j-1]=='#'){
	//				cout<<"valido???"<<endl;
					mat[i][j-1]='+';
//					cout<<"------------------"<<mat[i][j-1]<<"  --------------"<<endl;
				}
			}
			
			if(j+1<12){
				if(mat[i][j+1]=='#'){
					mat[i][j+1]='+';
				}
			}
			if(i-1>0){
				if(mat[i-1][j]=='#'){
					mat[i-1][j]='+';
				}
			}
			
			if(i+1<12){
				if(mat[i+1][j]=='#'){
					mat[i+1][j]='+';
				}
			}
		if((i+1<12)&&(j+1<<12)){
			if(mat[i+1][j+1]=='#' ){
				mat[i+1][j+1]='+';
			}	
		

		}
		if(i-1> 0 && j+1<12){
					if(mat[i-1][j+1]=='#'){
				mat[i-1][j+1]='+';
			}	
		
		}if(i+1<12 && j-1>0){
			if(mat[i+1][j-1]=='#'){
				mat[i+1][j-1]='+';
			}	
		}	

	}else if(pieza=='#'){
			if((i-1>0) && (j-1>0) ){
				if(mat[i-1][j-1]=='+' ){
					mat[i-1][j-1]='#';
				}	
			}
			if(j-1>0){
				if(mat[i][j-1]=='+'){
					mat[i][j-1]='#';
				}
			}
			
			if(j+1<12){
				if(mat[i][j+1]=='+'){
					mat[i][j+1]='#';
				}
			}
			if(i-1>0){
				if(mat[i-1][j]=='+'){
					mat[i-1][j]='#';
				}
			}
			
			if(i+1<12){
				if(mat[i+1][j]=='+'){
					mat[i+1][j]='#';
				}
			}
		if((i+1<12)&&(j+1<<12)){
			if(mat[i+1][j+1]=='+' ){
				mat[i+1][j+1]='#';
			}	
		

		}
		if(i-1> 0 && j+1<12){
					if(mat[i-1][j+1]=='+'){
				mat[i-1][j+1]='#';
			}	
		
		}if(i+1<12 && j-1>0){
			if(mat[i+1][j-1]=='+'){
				mat[i+1][j-1]='#';
			}	
		}	


	}	

}
bool vivo(char pieza,char** mat){
	bool sigue =false;
	int cont=0;
	for(int i=1;i<12;i++){
		for(int j=1;j<12;j++){
			if(mat[i][j]==pieza){
			cont++;
		}
	}
	}
	if(cont==0){
		sigue=false;
	}else if(cont!=0){
		sigue=true;
	
	}
cout<<cont<<" CONTADOR-------"<<sigue<<endl;
return sigue;
}	

