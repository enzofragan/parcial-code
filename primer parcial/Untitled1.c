    int opcion;
    char seguir;
    int valorAlta;
    int valorBaja;
    int valorModificacion;
    char auxEdad[50];///auxiliar para validar si es numero y edad edad o otra parecido
    int edad;
    int contador1 = 0;
    int contador2 = 0;
    int contador2 = 0;///si se va acontar con estructura hacerlo fuera del main
    do
    {
     printf("1. opcionalta\n2. opcionbaja\n3. opcionmodificacion\n4. opcionmostrar\n5. opcionetc\n6. salir\nElija una opcion: ");
     scanf("%d",&opcion);


     switch(opcion)
        {
        case 1:
            alta
        break;

        case 2:
            baja
        break;

        case 3:
            modificacion
        break;

        case 4:
        mostrar lista o solo
        break;

        case 5:
           etc
        break;

        case (ultimo case):
            salir
            printf("Desea salir S/N? \n");
            fflush(stdin);
            seguir=getche();
            break;
        }

    }while(seguir!='s');///menu



    typedef struct
    {
        char [50];
        int conexion entre dos estructuras; (dato en comun)
        int ???;
        int ???;
        int ???;
        int ???;
        int estado;
    }eProducto;

    typedef struct
    {
        etc
        int ;
        int ;
        char [50];
        int estado;

    }nombre de la etructura;///conexion por dato en comun
/////////////////////////////////////////////////////////////////////////////
    struct cd {
     char ej[30];
     char ej[25];
     float ej;
     int ej;
    } ej = {     /* inicializamos la estructura ej crea con sus valores
                   * usando las definiciones iniciales*/
            "Canciones Bebe", /* char1 */
            "Pinocho", /* char2 */
            12.50, /* float */
            16 /* int */
	  };///inicializar desde la estructura
/////////////////////////////////////////////////////////////////////////////
	  struct cliente
        {
            char ej char[25];
            /* agregamos la estructura infopersona
             * con nombre direcc_cliente
             */
            struct estructuraConeccion ???;
            int estado;
        };
    struct estructuraConeccion
        {
            char ???[25];
            char ???[20];
            char ???[20];
            int estado;
        };///conexion entre estructuras
/////////////////////////////////////////////////////////////////////////////
        int inicio(estructura lista[],int limite)///inicia los valores
        {
            int retorno=-1;
            int i;
            if(limite>0)
            {
                retorno=0;
                for(i=0; i<limite; i++)
                {
                    lista[i].estado= 1;///1=libre  0=ocupado
                    lista[i].???=0;
                    lista[i].???=0;
                    strcpy(lista[i].???(char),"");
                }
            }
            return retorno;
        }///inicio por prototipo
/////////////////////////////////////////////////////////////////////////////
        int autoIncrementar(estructura lista[],int limite)///id auto incrementable
        {
            int retorno = 0;
            int i;
            if(limite > 0 && lista != NULL)///mientrar el limite sea myor a 0 y haya algo
            {
                for(i=0; i<limite; i++)
                {
                    if(lista[i].estado == 0)///si el anterior esta ocupado
                    {
                            if(lista[i].???>retorno)///y esa id sea mayor al retorno
                            {
                                 retorno=lista[i].???;///devuelve esa id
                            }

                    }
                }
            }

            return retorno+1;///y retorna el lugar siguiente
        }///auto incrementar
/////////////////////////////////////////////////////////////////////////////
        int lugarLibre(estructura lista[], int limite)
        {
            int retorno=-1;
            int i;
            if(limite>0)///mientras la lista inicie
            {
                retorno=-2;
                for(i=0;i<limite;i++)/// y no sobre pase la limite
                {
                    if(lista[i].estado==1)///encontrar un lugar libre
                    {
                        retorno=i;
                        //printf("-----%d-----\n",retorno);
                        break;
                    }
                }
            }
            return retorno;
        }///busca lugar libre
/////////////////////////////////////////////////////////////////////////////
        int mostrarSolo(estructura lista)///muestra el usuario guardado
        {
            printf("%d---%s\n",lista.???,lista.???(char));
        }///muestra uno solo
/////////////////////////////////////////////////////////////////////////////
        int mostrarLista(estructura lista[],int limite)///mostra la lista de usuario
        {
            int retorno = -1;
            int i;
            if(limite > 0 && lista != NULL)///si no obrepara el limite y halla algo en la lista
            {
                retorno = 0;

                for(i=0; i<limite; i++)
                {
                    if(lista[i].estado==0)///si esta coupado lo muestra
                    {
                        mostrarSolo(lista[i]);
                    }
                }
            }
            return retorno;
        }///muestra lista completa

/////////////////////////////////////////////////////////////////////////////
        int alta(estructura lista[],int limite)///pide un nuevo usuario
        {
            int retorno=-1;
            int i;
            int id;
            int numero;
            if(limite>0 && lista != NULL)
            {
                retorno=-2;
                i=lugarLibre(lista,limite);///si encuentra un lugar libre
                if(i>=0)
                {
                    id=autoIncrementar(lista,limite);///pasa al id del siguiente al original
                      printf("ingrese el ???:");///
                        fflush(stdin);
                        gets(aux);
                        while(numeroV(aux)==0)
                        {
                            printf("ingrese un numero valido:");///
                            fflush(stdin);
                            gets(aux);
                        }
                        numero=atoi(aux);///combierte el char en int y lo guarda
                    printf("ingrese el nombre del usuario: ");///pider el nombre y valida
                    fflush(stdin);
                    gets(lista[i].???(char));
                    while(esLetra(lista[i].???(char))==0)
                    {
                        printf("ingrese un nombre valido: ");
                        fflush(stdin);
                        gets(lista[i].???(char));
                    }
                    printf("ingrese contraseña: ");///pide contraseña
                    fflush(stdin);
                    scanf("%d",&lista[i].???(edad));
                    lista[i].???=id;///la id que se guarda es la que devuelve la funcion anterio
                    lista[i].estado=0;///cambiar el estado a ocupado
                    retorno=0;
                }

            }
            return retorno;
        }///alta con autoincrementar
/////////////////////////////////////////////////////////////////////////////
        int buscar(estructura lista[],int limite)///busca el usuario para la baja o modificacion
        {
            int id;
            char nombre[50];
            int contra;
            int indice=-1;
            int i;
            char buff[50];

            printf("ingrese el id del usuario: ");
            fflush(stdin);
            gets(buff);///pide el numero com char
            while(esNumero(buff)==0)///valida si es numero o no
            {
                printf("ingrese un id valido: ");
                fflush(stdin);
                gets(buff);
            }
            id = atoi(buff);///los combierte a numero (atoi)
            printf("ingrese el nombre del usuario: ");
            fflush(stdin);
            gets(nombre);///pide el nombre
            while(esLetra(nombre)==0)///valida si es solo string
            {
                printf("ingrese un nombre valido: ");
                fflush(stdin);
                gets(nombre);
            }
            printf("ingrese la contraseña del usuario: ");///extra: pide contraseña
            fflush(stdin);
            scanf("%d",&contra);

            for (i=0;i<limite;i++)
            {
                if(id==lista[i].idUsuario && strcmp(nombre,lista[i].nombre)==0 && contra==lista[i].contrase)///si son iguales lo encontro
                {
                    indice=id;///de vuelve el id encontrado
                    break;
                }
                else
                {
                    indice=-2;
                }
            }
            return indice;
        }///buscar para baja o modif
/////////////////////////////////////////////////////////////////////////////
        int modificacion(estructura lista[],int limite)///modificar el usuario
        {
            int busquedaM;
            char respuesta;
            char respuestaM;
            char auxchar[50];
            int auxint;
            int indice=0;
            int i;

            busquedaM=buscar(lista,limite);///busca el usuario

            for(i=0;i<limite;i++)
            {
                if(busquedaM>=0 && lista[i].idUsuario==busquedaM)///si esta y el id es el mismo que el original
                {
                    mostrarSolo(lista[i]);///muestra el usuario

                    printf("desea modificar a este usuario? s/n: ");///pregunta si lo modificara
                    fflush(stdin);
                    respuesta=getche();

                    while(respuesta!='s' && respuesta!='n')///valida la recpuesta
                    {
                        printf("\ningrese un valor valido s/n: ");
                        fflush(stdin);
                        respuesta=getche();
                    }

                    if(respuesta=='s')///si es si pide los nuevos datos
                    {
                        printf("\ningrese el nuevo nombre del usuario: ");///pide de nuevo el nombre y lo guarda en un auxiliar
                        fflush(stdin);
                        gets(auxchar);
                        while(esLetra(auxchar)==0)
                        {
                            printf("\ingrese un nombre valido: ");
                            fflush(stdin);
                            gets(auxchar);
                        }
                        printf("\ingrese la nueva contraseña: ");///pide de nuevo la contraseña y la guarda en una auxliar
                        fflush(stdin);
                        scanf("%d",&auxint);

                        printf("\nel nuevo nombre es: %s\ny el la nueva contraseña es: %d\n",auxchar,auxint);///muestra el nuevo nombre y contraseña

                        printf("\ndesea aplicar estos cambios? s/n: ");///pregunta si desea aplicar los cambios
                        fflush(stdin);
                        respuestaM=getche();

                        while(respuestaM!='s' && respuestaM!='n')///valida la respuesta
                        {
                            printf("\ningrese un valor valido s/n: ");
                            fflush(stdin);
                            respuestaM=getche();
                        }

                        if(respuestaM=='s')
                        {
                            strcpy(lista[i].???(char),auxchar);
                            lista[i].???(int)=auxint;
                        }
                        else if(respuestaM=='n')
                        {
                            indice=-2;
                        }
                    }
                    else if(respuesta=='n')
                    {
                        indice=-1;
                    }
                }
            }
            return indice;
        }///modificacion
/////////////////////////////////////////////////////////////////////////////
        int baja(estructura lista[],int limite)///pide se desea dar de baja un usuario
        {
            int busquedaB;
            char respuesta;
            int indice=0;
            int i;

            busquedaB=buscar(lista,limite);///busca el usuario

            for(i=0;i<limite;i++)
            {
                if(busquedaB>=0 && lista[i].???==busquedaB)///si esta y el id es el mismo que el original
                {
                    mostrarSolo(lista[i]);///muestra el usuario
                    printf("dara de baja a este usuario? s/n: ");///pregunta si lo dara de baja
                    fflush(stdin);
                    respuesta=getche();
                    while(respuesta!='s' && respuesta!='n')///si no es ni si ni no
                    {
                        printf("\ningrese un valor valido s/n: ");
                        fflush(stdin);
                        respuesta=getche();
                    }
                    if(respuesta=='s')///si es si devuelve es valor al inicio
                    {
                        lista[i].estado=1;
                        lista[i].???=0;
                        lista[i].???(int)=0;
                        strcpy(lista[i].???(char),"");
                    }
                    else if(respuesta=='n')
                    {
                        indice=-1;
                    }
                }
            }
            return indice;
        }///baja
/////////////////////////////////////////////////////////////////////////////
        int numeroV(char num[])
        {
            int i=0;
            while(num[i] != '\0')
            {
                if(!(isdigit(num[i])))///si el char no es un digito
                {
                    return 0;///es letra
                }
                i++;
            }
            return 1;
        }

        int letraV(char nom[])
        {
            int i=0;
            while(nom[i] != '\0')///mientras no sea /0 osea alla algo
            {
                if((nom[i] != ' ') && (nom[i] < 'a' || nom[i] > 'z') && (nom[i] < 'A' || nom[i] > 'Z'))///si tiene espacio y no esta entre a y z
                {
                    return 0;///es numero
                }
                i++;
            }
            return 1;
        }
        int edadV(int edades)
        {
            if(edades>99 || edades<0)
            {
                return 0;
            }
            return 1;
        }///validacion de letras, numeros y edades


        float promedio(int valores[], int limite)
        {
            int cant = limite;
            float suma;
            float promedio;

            for (i = 0; i < limite; i++)
                suma = sums(valores[i],limite);

                promedio=suma/cant;

            return promedio;
        }
        ///in main
        for (i = 0; i < n; ++i)
        {
            printf("  Nota: ");
            scanf("%d", &notas[i]);
        }
        printf("El promedio de %s es %.1f\n", nombre, promedio o suma(notas, contidad de lo que se calculara));///

        float sums (int valores[], int limite)
        {
            int i;
            float suma = 0.0;

            for (i = 0; i < limite; i++)
                suma += valores[i];

                return suma;
        }///suma y promedio

    void menu();
    void menu()
    {
        printf("1- Ingresar 1er operando (A= %f)\n",numeroUno);
        printf("2- Ingresar 2do operando (B= %f)\n",numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
    }

    opcion=menu();
    ///menu en biblioteca o prototipo


    int flag=0;
    int max;
    int min;
     if(flag==0 || numero>max)
        {
            max=numero;
        }
        if (flag==0 || numero<min)
        {
            min=numero;
            flag=1;
        }///maximo y minimo
