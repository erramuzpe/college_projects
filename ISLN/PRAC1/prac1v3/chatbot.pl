#!/usr/bin/perl

open(PREG,"+<preg");	#Archivo de preguntas o respuestas si no se 
			#encuentra patrón
	#Voy a hacer el tratamiento de PREG en un bucle fuera del bucle principal,
	#no como con TEXT, que lo recorre cada vez y no es eficiente. 
	#(pero permite editarlo, durante la ejecución. 

while ($line=<PREG>) { 
	chomp $line; #elimina /n
	push @preguntas,$line;
}
#TRATAMIENTO 10000palabras
#while ($line=<PAL>) { 
#	chomp $line; #elimina /n
#	push @palabras,$line;
#}



#BUCLE PRINCIPAL
while($a==$b) {  	#bucle sin fin

	open(TEXT,"+<bot");	#Archivo de respuestas
	open(PAL,"+<10000_palabras.txt");

	print("Tu>");
	$said = <STDIN>;
	chomp $said; #quitamos el /n
	@encontrado = ();
	$repetido =0;

	#ZONA MATAR EL CHAT CON CLAVE
	if ($said eq "Adios") {
		close (LOG);
		close (TEXT);
		die ("El chat muere!");
	}

	#ZONA EXPRESIONES REGULARES
	if ($said eq "Dime las palabras que empiecen y acaben con la misma vocal") {
		while ($line=<PAL>) { 
		   chomp $line;
		   if ($line =~ /^([aeiou]).*\1$/) {
		   	print ("".$line.  "\n");
		   }
		}
	}
	elsif ($said eq "Dime las palabras que acaben en vocal acentuada") {
		while ($line=<PAL>) { 
		   chomp $line;
		   if ($line =~ /[áéíóú]$/) {
		   	print ("".$line.  "\n");
		   }
		}
	}
	elsif ($said eq "Dime las palabras que solo contengan la vocal u") {
		while ($line=<PAL>) { 
		   chomp $line;
		   if ($line !~ /[aeioáéíó]/ && $line =~ /[u]/ ) {
		   	print ("".$line.  "\n");
		   }
		}
	}
	elsif ($said eq  "Dime las palabras con cuatro o más letras s") {
		while ($line=<PAL>) { 
		   chomp $line;
		   if ($line =~ /.*s.*s.*s.*s.*/) {
		   	print ("".$line.  "\n");
		   }
		}
	}
	elsif ($said eq  "Dime las palabras que contengan 2 vocales") {
		while ($line=<PAL>) { 
		   chomp $line;
		   if ($line =~ /^[^aeiouáéíóú]*[aeiouáéíóú][^aeiouáéíóú]*[aeiouáéíóú][^aeiouáéíóú]*$/) {
		   	print ("".$line.  "\n");
		   }
		}
	}


	#ZONA COMPARAR CON DICCIONARIO

	#RECORRE TODO EL DICCIONARIO EN BUSCA DE LAS PALABRAS QUE 
	#APAREZCAN Y ALMACENA RESPUESTAS EN @encontrado. 

	while ($line=<TEXT>) { 


		chomp $line; #elimina /n
		#print ( "".$line.  "\n");

		($wsaid, $bsaid) = split /\t/, $line;
		#print ( "".$wsaid.  "\n");
		#print ( "".$bsaid.  "\n");

		if($said =~ /$wsaid/i) {
			push @encontrado,$bsaid;
			$wsaidb=$said;

			#echo "hola" | festival --tts (español)
		} 
		#sleep(1);
	}

	
	if(@encontrado == 0) {
			#ZONA DE PREGUNTAS SI @encontrado vacio
			#Habla algo de @preguntas
			$elementoaleatorio = $preguntas[rand @preguntas];
			print ("Bot>" . $elementoaleatorio . "\n");
			#print @preguntas;
			
			
	} 
	else {
			#ZONA HABLAR ALEATORIAMENTE ALGO @encontrado
			$elementoaleatorio = $encontrado[rand @encontrado];
			print ("Bot>" . $elementoaleatorio . "\n");
			#print @encontrado;
	
	}




	#ZONA CONTROL REPETICIONES
	open(LOG,"+<log");
	while ($repe=<LOG> and $repetido==0) { 
		chomp $repe; #elimina /n

		if($said eq $repe) {
			print ("Bot>Por cierto, se está repitiendo.\n");
			$repetido = 1;
		}
	}
	
	#Se escribe en el log si no está dentro todavía.
	if ($repetido==0){
		open(LOG,">>log");	#Archivo log
		print LOG ($said . "\n");
		close (LOG);
	}


	@encontrado = ();

	close (TEXT);
	close (LOG);
	

}
close (PREG);

