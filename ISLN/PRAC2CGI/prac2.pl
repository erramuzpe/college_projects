#!/usr/bin/perl
#use strict;
use CGI qw(param);
use utf8;
use XML::LibXML;
binmode(STDOUT, ':utf8');


#PRAC2.3: Desaparece el analisis de las 100000 palabras
#La variable del idioma funciona.
#Esta practica utiliza el XML del ChatBot SARA
#en vez de mi fichero de texto.


$idioma = $ENV{HTTP_ACCEPT_LANGUAGE};

print "Content-Type:text/html\n\n";
print "<html>\n<head> <meta http-equiv='Content-Type'content='text/html; charset=utf8'></head> <body>\n";
print "<form action='prac2.cgi' method='get'>\n";

#ELEGIR LENGUA (PREDETERMINADA: EUSKARA)
#EL BOT SOLO RESPONDE EN ESPAÑOL, PERO SE PODRÍA CAMBIAR
if ($idioma =~ "eu") {
print "Esan zerbait: <input type='text' name='intro' />\n";
print "<input type='submit' value='Bidali' />\n";
}
else{
print "Dime algo: <input type='text' name='intro' />\n";
print "<input type='submit' value='Enviar' />\n";
}
print "</form>\n";



#SE ELEGIRÍA ENTRE DIFERENTES XMLs POR IDIOMA, PERO NO HE ENCONTRADO NADA EN EUSKARA
my $parser = XML::LibXML->new();
my $doc = $parser->parse_file('/var/www/cgi-bin/sara.xml');


open(PREG,"+<preg");	#Archivo de preguntas o respuestas si no se 
			#encuentra patrón
while ($line=<PREG>) { 
	chomp $line; #elimina /n
	push @preguntas,$line;
}

if (param()) { # se procesa si hay entrada de datos
    my $said = param('intro');


#######################
#######################
######ZONA BOT#########
#######################
#######################

	
	@encontrado = ();
	$repetido =0;

	#ZONA COMPARAR CON DICCIONARIO

	#RECORRE TODO EL DICCIONARIO EN BUSCA DE LAS PALABRAS QUE 
	#APAREZCAN Y ALMACENA RESPUESTAS EN @encontrado. 
	foreach my $category ($doc->findnodes('//category')) {

		foreach my $pattern ($category->findnodes('./pattern')) {

			$wsaid = $pattern->to_literal();
			$wsaid =~ s/\*/(.+)/g; 		

			if($said =~ /$wsaid/i) { 
					$primera = $1;
					$segunda = $2;
				foreach my $li ($category->findnodes('./template/random/li')){
					$frase = $li->toString();
			
					$frase =~ s/<star.+?>/$primera/ ;
					$frase =~ s/<star.+?>/$segunda/ ;
					$frase =~ s/<li>/ / ;
					$frase =~ s/<\/li>/ / ;

					push @encontrado,$frase;
				}
				$wsaidb=$said;
			} 
			
		
		} #ACABA FOREACH PATTERN
	} #ACABA FOREACH CATERGORY
	
	if(@encontrado == 0) {
			#ZONA DE PREGUNTAS SI @encontrado vacio
			#Habla algo de @preguntas
			$elementoaleatorio = $preguntas[rand @preguntas];
			print ("Bot>" . $elementoaleatorio . "<br>");
	} 
	else {
			#ZONA HABLAR ALEATORIAMENTE ALGO @encontrado
			$elementoaleatorio = $encontrado[rand @encontrado];
			print ("Bot>" . $elementoaleatorio . "<br>");
	}



	#ZONA CONTROL REPETICIONES
	open(LOG,"+<log");
	while ($repe=<LOG> and $repetido==0) { 
		chomp $repe; #elimina /n

		if($said eq $repe) {
			print ("Bot>Por cierto, se está repitiendo.<br>");
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

	close (LOG);
	close (PREG);


}

#######################
#######################
####FIN ZONA BOT#######
#######################
#######################

else { 	# se procesa solo si no hay entrada de datos
	print "No has metido nada<br>";
}
print "</body>\n</html>";
exit;

