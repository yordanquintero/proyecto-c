#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


void menucliente();
void crearcliente();
void mostrarCliente1();
void mostrarclientes();
int buscarCliente();
int buscarCliente1();
void eliminarcliente();
void modificarcliente();
void copiar(char cadena1[],char cadena2[]);
void menu();

int cantid;
int totalf[50];

int cantt;
int posf;
int cap;

void cuadro2();
void crearProducto ();
void mostrarproductos ();
void modificarProductos();
void eliminarProducto();
int buscarProducto() ;
int buscarProducto1();
void menuProductos ();
void mostrarProducto(int id);
void mostrarproductos1();


void crearFactura();
void menuFactura();
void mostrarFactura();
void mostrarFactura1();
int buscarfactura();
int pagar();
void mostrarfactura2(int idf);
void mostrarfactura3(int idf);

void  gotoxy ( int x, int y) {
    HANDLE hcon = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos. X = x;
    dwpos. Y = y;
    SetConsoleCursorPosition (hcon, dwpos);
}

char estado[20];
char pagada[]="si paga";
char nopagado[]="no paga";
struct  clientes {
int id;
int cedula;
char nombre [100];
char direccion [ 100 ];
char telefono [ 100 ];
} cliente[ 100 ],*pcliente=cliente;

int numcliente=0;

struct producto{

  	int idp;
	char nombre[45];
	float valor;
}productos[100],*pproductos= productos;

int numProductos=0;
int idp,j,idpp;


struct facturas{

   int idc;
   char nombre[100];
   char direccion[100];
   char telefono[100];
   int cedulaf;
   char nombrep[100];
    char estadof[100];

int id;
int cantidad;
float valor;
int estado;
int total;
}facturaf[100],*pfactura=facturaf;

int numFacturas=0;
int cantProductos=0;
 int con,id;
int canfactura;


void cuadro2(){
	int i;
	//Horizontales
	for(i = 2; i < 111; i++){
		gotoxy(i, 0); printf("%c", 205); //Horizontales Superiores
		gotoxy(i, 25); printf("%c", 205);//Horizontales Inferiores
	}
	//Verticales
	for(i = 1; i < 25; i++){
		gotoxy(2, i); printf("%c", 186); //Verticales Izquierda
		gotoxy(111, i); printf("%c", 186);//Verticales Derecha
	}
	//Esquinas
	gotoxy(2, 0); printf("%c", 201);
	gotoxy(2, 25); printf("%c", 200);
	gotoxy(111,0); printf("%c", 187);
	gotoxy(111, 25); printf("%c", 188);
}


int main(){
system("color E0");
menu();

    return 0;
}




void menu (){
int opcion;
do{
        system("cls");
        cuadro2();
     gotoxy(50,2);
     printf("MENU PRINCIPAL.\n");
	gotoxy(40,4);
	printf("1. Clientes.\n");
	gotoxy(40,6);
	printf("2. Productos.\n");
	gotoxy(40,8);
	printf("3. Facturas. \n");
	gotoxy(60,6);
	printf("Ingrese una opcion: ");
scanf("%d", &opcion);
    system("cls");
		switch(opcion){
			case 1: menucliente();
				break;
			case 2:menuProductos();
				break;
			case 3:menuFactura();
				break;
			default: printf("Opcion invalida\n");
			}
	}while(opcion != 0);
}


void menucliente (){
    int opcion;
do{
        system("cls");
        cuadro2();
        gotoxy(50,2);printf("Menu Clientes \n");
        gotoxy(40,4);printf("1. Crear Cliente\n");
        gotoxy(40,6);printf("2. Ver Clientes\n");
        gotoxy(40,8);printf("3. Modificar Cliente\n   ");
        gotoxy(60,4);printf("4. Eliminar Cliente\n   ");
        gotoxy(60,6);printf("5. Buscar Cliente\n   ");
        gotoxy(62,8);printf("0. Menu Principal\n  ");
        gotoxy(50,10);printf("Ingrese una opcion:   ");
       scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1: crearcliente();
            break;
            case 2: mostrarclientes();
            break;
            case 3:modificarcliente();
            break;
            case 4:eliminarcliente();
            break;
            case 5:buscarCliente();
            break;
            case 0:
            break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);
}


void  crearcliente(){
cuadro2();
fflush (stdin);
gotoxy ( 50 , 5 ); printf ( " -------------- \n " );
gotoxy ( 50 , 6 ); printf ( " CREAR CLIENTE " );
gotoxy ( 50 , 7 ); printf ( " --------------- \n " );
gotoxy ( 50 , 8 ); printf ( " Ingrese los datos del cliente \n " );
(cliente+numcliente)->id=numcliente;
gotoxy ( 50 , 9 ); printf ( " Nombre: " );
fgets ((pcliente+numcliente)->nombre, 30 , stdin);
gotoxy ( 50 , 10 ); printf ( " Direccion: " );
fgets ((pcliente+numcliente)->direccion , 30 , stdin);
gotoxy ( 50 , 11 ); printf ( " Telefono: " );
fgets ((pcliente+numcliente)->telefono , 30 , stdin);
gotoxy ( 50 , 12 ); printf ( " Cedula: " );
scanf ("%d",&(pcliente+numcliente)->cedula );
numcliente++;
gotoxy ( 50 , 13 ); printf ( " Cliente registrado con exito \n " );
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
system("pause");
}


void mostrarclientes (){
printf("-----------------\n");
printf("LISTA DE CLIENTES\n");
printf("-----------------\n");
for (int i=0;i<numcliente;i++){
    printf("\ncliente #%d\n",i+1);
    printf("nombre: %s",(pcliente+i)->nombre);
    printf("direccion: %s",(pcliente+i)->direccion);
    printf("telefono: %s",(pcliente+i)->telefono);
    printf("cedula: %d\n",(pcliente+i)->cedula);
    }
system("pause");
}
void mostrarCliente(int idCliente){
    cuadro2();
	gotoxy(50,5);printf("Mostrar Clientes\n");
	gotoxy(50,6);printf("Cliente No. %d\n", (pcliente+idCliente)->id + 1);
	gotoxy(50,7);printf("Nombre del Cliente: %s", (pcliente+idCliente)->nombre);
	gotoxy(50,8);printf("Direccion del Cliente: %s", (pcliente+idCliente)->direccion);
	gotoxy(50,9);printf("Telefono del Cliente: %s", (pcliente+idCliente)->telefono);
	gotoxy(50,10);printf("Cedula del Cliente: %d\n", (pcliente+idCliente)->cedula);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}
void mostrarCliente1(int idCliente){
    cuadro2();
	gotoxy(50,6);printf("FACTURA DEL CLIENTE #%d\n",numFacturas);
	gotoxy(50,7);printf("Cliente No. %d\n", (pcliente+idCliente)->id);
	gotoxy(50,8);printf("Nombre del Cliente: %s", (pcliente+idCliente)->nombre);
	gotoxy(50,9);printf("Direccion del Cliente: %s", (pcliente+idCliente)->direccion);
	gotoxy(50,10);printf("Telefono del Cliente: %s", (pcliente+idCliente)->telefono);
	gotoxy(50,11);printf("Cedula del Cliente: %d\n", (pcliente+idCliente)->cedula);
	gotoxy(50,12);printf("Cantidad: %d\n",cantid);
    gotoxy(50,13);printf("Nombre del Producto: %s", (pproductos+idpp)->nombre);
	gotoxy(50,14);printf("Valor  producto: %.2f\n", (pproductos+idpp)->valor);
    totalf[numFacturas]=cantid*((pproductos+idpp)->valor);
   gotoxy(50,15); printf("total: %d",totalf[numFacturas]);
	gotoxy(50,16);printf("estado:%s",estado);
	printf("\n\n\n\n\n\n\n\n\n\n");

            (pfactura+numFacturas)->idc=(pcliente+cap)->id;
            strcpy(((pfactura+numFacturas)->nombre),((pcliente+cap)->nombre));
            strcpy(((pfactura+numFacturas)->direccion),((pcliente+cap)->direccion));
            strcpy(((pfactura+numFacturas)->telefono),((pcliente+cap)->telefono));
            ((pfactura+numFacturas)->cedulaf)=((pcliente+cap)->cedula);
            (pfactura+numFacturas)->cantidad=cantid;
            strcpy(((pfactura+numFacturas)->nombrep),((pproductos+idpp)->nombre));
            (pfactura+numFacturas)->valor=(pproductos+idpp)->valor;
            (pfactura+numFacturas)->total=totalf[numFacturas];
            strcpy(((pfactura+numFacturas)->estadof),estado);

    numFacturas++;

	system("pause");
}


void mostrarFactura1(){

    for(int i=0;i<numFacturas;i++){
    printf("FACTURA DEL CLIENTE #%d\n",i);
	printf("Cliente No. %d\n",(pfactura+i)->idc);
	printf("Nombre del Cliente: %s",(pfactura+i)->nombre);
	printf("Direccion del Cliente: %s",(pfactura+i)->direccion);
	printf("Telefono del Cliente: %s",(pfactura+i)->telefono);
    printf("Cedula del Cliente: %d\n",(pfactura+i)->cedulaf);
	printf("Cantidad: %d\n",(pfactura+i)->cantidad);
    printf("Nombre del Producto: %s",(pfactura+i)->nombrep);
	printf("Valor  producto: %.2f\n",(pfactura+i)->valor);
    printf("total: %d\n",(pfactura+i)->total);
	printf("estado:%s",(pfactura+i)->estadof);
    printf("\n\n\n");
        }
        system("pause");
}



void mostrarfactura2(int idf){
    cuadro2();
    gotoxy(50,6);printf("FACTURA DEL CLIENTE");
	gotoxy(50,7);printf("Cliente No. %d\n",(pfactura+idf)->idc);
	gotoxy(50,8);printf("Nombre del Cliente: %s",(pfactura+idf)->nombre);
	gotoxy(50,9);printf("Direccion del Cliente: %s",(pfactura+idf)->direccion);
	gotoxy(50,10);printf("Telefono del Cliente: %s",(pfactura+idf)->telefono);
    gotoxy(50,11);printf("Cedula del Cliente: %d\n",(pfactura+idf)->cedulaf);
	gotoxy(50,12);printf("Cantidad: %d\n",(pfactura+idf)->cantidad);
    gotoxy(50,13);printf("Nombre del Producto: %s",(pfactura+idf)->nombrep);
	gotoxy(50,14);printf("Valor  producto: %.2f\n",(pfactura+idf)->valor);
    gotoxy(50,15);printf("total: %d\n",(pfactura+idf)->total);
    gotoxy(50,16);printf("estado:%s",(pfactura+idf)->estadof);
    gotoxy(50,17);printf("\n\n\n\n\n\n\n\n\n");
    system("pause");

}

void mostrarfactura3(int idf){
    cuadro2();
    int n;
    gotoxy(50,6);printf("FACTURA DEL CLIENTE");
	gotoxy(50,7);printf("Cliente No. %d\n",(pfactura+idf)->idc);
	gotoxy(50,8);printf("Nombre del Cliente: %s",(pfactura+idf)->nombre);
	gotoxy(50,9);printf("Direccion del Cliente: %s",(pfactura+idf)->direccion);
	gotoxy(50,10);printf("Telefono del Cliente: %s",(pfactura+idf)->telefono);
    gotoxy(50,11);printf("Cedula del Cliente: %d\n",(pfactura+idf)->cedulaf);
	gotoxy(50,12);printf("Cantidad: %d\n",(pfactura+idf)->cantidad);
    gotoxy(50,13);printf("Nombre del Producto: %s",(pfactura+idf)->nombrep);
	gotoxy(50,14);printf("Valor  producto: %.2f\n",(pfactura+idf)->valor);
    gotoxy(50,15);printf("total: %d\n",(pfactura+idf)->total);
    gotoxy(50,16);printf("estado:%s",(pfactura+idf)->estadof);
    gotoxy(50,17); printf("desea pagarla ? si=1 no=0: ");
    scanf("%d",&n);
    printf("\n\n\n\n\n");
        if(n==1){
        strcpy((pfactura+idf)->estadof,pagada);
    }



}



int buscarCliente(){
    cuadro2();
	int cedulaBuscar, i;
	gotoxy(50,6);printf("Buscar Cliente.  ");
	gotoxy(50,7);printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");
	for(i = 0; i < numcliente; i++){
		if(cedulaBuscar == (pcliente+i)->cedula){
			mostrarCliente((pcliente+i)->id);
			return (cliente+i)->id;
		}
	}
	cuadro2();
	gotoxy(50,8);printf("El cliente no existe \n");
		printf("\n\n\n\n\n\n\n\n");

	system("pause");
	return -1;
system("pause");
}

int buscarCliente1(){

    system("cls");
    cuadro2();
	int cedulaBuscar, i,n;
	gotoxy(50,6);printf("Buscar Cliente.  ");
	gotoxy(50,7);printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");
	for(i = 0; i < numcliente; i++){
		if(cedulaBuscar == (pcliente+i)->cedula){
                cap=(pcliente+i)->id;
			mostrarCliente1((pcliente+i)->id);
			return (cliente+i)->id;
		}
	}
	gotoxy(50,8);printf("El cliente no existe \n");
	cuadro2();
		printf("\n\n\n");

	system("pause");
	return -1;

}

void eliminarcliente(){
    cuadro2();
gotoxy(50,5);printf("ELIMINAR CLIENTE\n");
int idcliente=buscarCliente();
if(idcliente!=-1){
    if(idcliente<numcliente){
        for(int i=idcliente;i<numcliente;i++){
            (pcliente+i+1)->id = (pcliente+i)->id;
            copiar((cliente+i)->nombre,(pcliente+i+1)->nombre);
            (pcliente+i)->cedula = (pcliente+i+1)->cedula;
            copiar((pcliente+i)->direccion,(pcliente+i+1)->direccion);
            copiar((pcliente+i)->telefono,(pcliente+i)->telefono);
        }
    }
    numcliente--;
}

}


void copiar(char cadena1[],char cadena2[]){
int contador=0;
for(int i=0;i<30;i++){
    if(cadena1[i]=='\n'){
        break;
    }
    contador++;
}
for(int i=0;i<contador;i++){
    cadena1[i]=cadena2[i];
}
}


void modificarcliente(){
    cuadro2();
gotoxy(50,5);printf("MODIFICAR CLIENTE\n");
int idcliente=buscarCliente();
if(idcliente!=-1){
gotoxy(50,6);printf("Cliente No. %d\n", idcliente + 1);
        fflush(stdin);
		gotoxy(50,15);printf("Nombre del Cliente: ");
		fgets((pcliente+idcliente)->nombre,30,stdin);
		gotoxy(50,16);printf("Direccion del Cliente: ");
		fgets((pcliente+idcliente)->direccion,30,stdin);
		gotoxy(50,17);printf("Telefono del Cliente: ");
		fgets((pcliente+idcliente)->telefono,30,stdin);
		gotoxy(50,18);printf("Cedula del Cliente: ");
		scanf("%d", &(pcliente+idcliente)->cedula);
		printf("\n");
		system("cls");
    }
}


void menuProductos (){
    int opcion;
do{
        system("cls");
        cuadro2();
        gotoxy(50,2);printf("Menu PRODUCTOS \n");
        gotoxy(40,4);printf("1. Crear producto\n");
        gotoxy(40,6);printf("2. Ver producto\n");
        gotoxy(40,8);printf("3. Modificar producto\n   ");
        gotoxy(60,4);printf("4. Eliminar producto\n   ");
        gotoxy(60,6);printf("5. Buscar producto\n   ");
        gotoxy(62,8);printf("0. Menu Principal\n  ");
        gotoxy(50,10);printf("Ingrese una opcion:   ");

       scanf("%d",&opcion);
        system("cls");

        switch(opcion){
            case 1: system("cls"); crearProducto ();
            break;
            case 2: system("cls"); mostrarproductos ();
            break;
            case 3: system("cls"); modificarProductos();
            break;
            case 4: system("cls"); eliminarProducto();
            break;
            case 5: system("cls"); buscarProducto() ;
            break;
            case 0: menu();
            break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);

}
void  crearProducto () {
fflush (stdin);
cuadro2();
gotoxy ( 50 , 5 ); printf ( " -------------- \n " );
gotoxy ( 50 , 6 ); printf ( " CREAR PRODUCTO " );
gotoxy ( 50 , 7 ); printf ( " --------------- \n " );
gotoxy ( 50 , 8 ); printf ( " Ingrese los datos del Producto \n " );
productos[numProductos].idp = numProductos;
gotoxy ( 50 , 9 ); printf ( " Nombre del producto: " );
fgets ((pproductos+numProductos)->nombre, 45 , stdin);
gotoxy ( 50 , 10 ); printf ( " Valor: $" );
scanf ("%f",&(pproductos+numProductos)->valor);
numProductos++;
gotoxy ( 50 , 11 ); printf ( " Producto registrado con exito \n " );
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
system("pause");
}

void mostrarproductos (){

printf("-----------------\n");
printf("LISTA DE PRODUCTOS	\n");
printf("-----------------\n");
for (int i=0;i<numProductos;i++){
    printf("-----------------\n");
    printf("Nombre: %s",(pproductos+i)->nombre);
    printf("Id: %d\n",(pproductos+i)->idp);
    printf("Valor %.2f\n", (pproductos+i)->valor);
    printf("-----------------\n");
    }
system("pause");
}
void mostrarproductos1(){

printf("-----------------\n");
printf("LISTA DE PRODUCTOS	\n");
printf("-----------------\n");
for (int i=0;i<numProductos;i++){
    printf("-----------------\n");
    printf("Id (numero): %d\n",(pproductos+i)->idp);
    printf("Nombre: %s",(pproductos+i)->nombre);
    printf("Valor %.2f\n", (pproductos+i)->valor);
    printf("-----------------\n");
    }

}

void mostrarProducto(int idp){
    cuadro2();
	gotoxy(50,6);printf("Nombre del Producto: %s", (pproductos+idp)->nombre);
	gotoxy(50,7);printf("Valor del producto: %.2f\n", (pproductos+idp)->valor);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}



int buscarProducto(){

	mostrarproductos1();
	int  i,j;
	gotoxy(50,6);printf("Buscar Producto.  ");
	gotoxy(50,7);printf("Ingrese el id del producto: ");
	scanf("%d",&i);
	system("cls");
	printf("\n");
	for(j = 0; j < numProductos; j++){
		if(i == (pproductos+j)->idp ){
			mostrarProducto((pproductos+j)->idp);
			return(pproductos+j)->idp;
			}
	}

	return  -1;

system("pause");

}

int buscarProducto1(){
    int n,i;
	gotoxy(50,6);printf("Buscar Producto.  ");
	gotoxy(50,7);printf("Ingrese el id del producto: ");
	scanf("%d",&i);
	fflush(stdin);
gotoxy(50,8); printf("ingrese la cantidad de productos a comprar: ");
scanf("%d",&cantid);

gotoxy(50,9);printf("pagada 1=si 0=no: ");
scanf("%d",&n);
for(int i=0;i<8;i++){
if(n==1){
   estado[i]=pagada[i];
    }if(n==0){
 estado[i]=nopagado[i];
    }

}
	system("cls");
	printf("\n");
	for(j = 0; j < numProductos; j++){
		if(i == (pproductos+j)->idp ){
                idpp=(pproductos+j)->idp;
			mostrarProducto((pproductos+j)->idp);
			return (pproductos+j)->idp;
			}
	}

}
void eliminarProducto(){

gotoxy(50,11);
printf("ELIMINAR PRODUCTO\n");

int idproducto ;
idproducto = buscarProducto();
if(idproducto!=-1){
    if(idproducto<numProductos){
        for(int i=idproducto;i<numProductos;i++){
            (pproductos+i+1)->idp = (pproductos+i)->idp;
            strcpy((pproductos+i)->nombre,(pproductos+i+1)->nombre);
            (pproductos+i)->valor = (pproductos+i+1)->valor;
        }
    }
    numProductos--;
}
}


void modificarProductos(){
int idproducto ;
system("cls");
gotoxy(50,5);printf("MODIFICAR PRODUCTO\n");
idproducto=buscarProducto();
if(idproducto != -1){
gotoxy(50,6);
        fflush(stdin);
		gotoxy(50,15);printf("Nombre del producto: ");
		fgets((pproductos+idproducto)->nombre, 30, stdin);
		gotoxy(50,16); printf("Valor del producto: ");
		scanf("%f", &(pproductos+idproducto)->valor);
        printf("\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		system("cls");
}
}

void menuFactura(){
	int opcion;
	do{
		system("cls");
		cuadro2();
		gotoxy(50,2);
		printf("MENU FACTURA.\n");
		gotoxy(40,4);
		printf("1. Crear Factura.\n");
		gotoxy(40,6);
		printf("2. Mostrar Factura.\n");
		gotoxy(40,8);
		printf("3. buscar factura. \n");
		gotoxy(40,10);
		printf("4. pagar factura. \n");
		gotoxy(40,12);
		printf("0. Menu principal. \n");
		gotoxy(60,6);
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: crearFactura();
		break;
		case 2:mostrarFactura1();
		break;
		case 3:buscarfactura();
		break;
		case 4:pagar();
		break;
		case 0: menu();
		default: printf("Opcion invalida");
		}
	}while(opcion != 0);
}

void crearFactura(){

mostrarproductos1();
buscarProducto1();
buscarCliente1();

}




int buscarfactura(){
    cuadro2();
    int cont=0;
    int aux;
    cuadro2();
	int cedulaBuscar ;
	gotoxy(50,6);printf("Buscar Cliente.  ");
	gotoxy(50,7);printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");



	for(int i = 0; i < numFacturas; i++){
    if(cedulaBuscar == ((pfactura+i)->cedulaf)){
                mostrarfactura2(i);
			return (facturaf+i)->cedulaf;
		}
	}
	cuadro2();
	gotoxy(50,8);printf("El cliente no existe \n");
		printf("\n\n\n\n\n\n\n\n");

	system("pause");
	return -1;
system("pause");

}

int pagar(){
    cuadro2();
    int cont=0;
    int aux;
    cuadro2();
	int cedulaBuscar ;
	gotoxy(50,6);printf("Buscar Cliente.  ");
	gotoxy(50,7);printf("Ingrese Cedula del cliente: ");
	scanf("%d", &cedulaBuscar);
	system("cls");
	printf("\n");



	for(int i = 0; i < numFacturas; i++){
    if(cedulaBuscar == ((pfactura+i)->cedulaf)){
                mostrarfactura3(i);

			return (facturaf+i)->cedulaf;
		}
	}
	cuadro2();
	gotoxy(50,8);printf("El cliente no existe \n");
		printf("\n\n\n\n\n\n\n\n");

	system("pause");
	return -1;
system("pause");

}




