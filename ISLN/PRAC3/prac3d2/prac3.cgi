#!/usr/bin/perl
#use strict;
use CGI qw(param);
use utf8;
use XML::LibXML;
use Net::Twitter;
binmode(STDOUT, ':utf8');


#PRAC3: 
#Hacer un programa que interrogue a twitter con un término, (p.e. 'Granada'), y busque en la respuesta los:
#1.- Hashtag que acompañan al término de búsqueda (palabras empezando por #)
#2.- Nombres propios
#Sacarlos por orden de frecuencias (primero los que más salen)

#GRAMATICA NP
$May = '[A-ZÁÉÍÓÚÑ]';
$Min = '[a-záéíóúñ]';
$Empieza_May = "(?:$May$Min+)";
$NP = "(?:$Empieza_May $Empieza_May*)";



    #$said = <STDIN>;
    my $said = "Granada";
    chomp $said;


	# Para entrar sin identificarse
	my $nt = Net::Twitter->new(legacy=>1);
	# Permite hasta 100 tweetts a la vez,
	# y hasta 1400 en total
	my $busqueda = $nt->search({q=>$said, lang=>'es', rpp=>60, page=>1});

	#print $busqueda. "\n";
	open(LOG,">log");
	for my $twitt (@{$busqueda->{'results'}}) {
		my $texto = $twitt->{'text'};
		#print "$texto\n";
		#Archivo log
		
		print LOG ($texto . "\n");
		
	}
	close (LOG);


	#BUSQUEDA HASTAG (sólo el primero de cada twitt)
	open(PAL,"+<log");
	open(HAS,">hastag");
	while ($line=<PAL>) { 
		chomp $line;
		#print $line . "\n";
		if ($line =~ /(#.*)/g) {
			$palabra = $1;
			#print ("".$palabra.  "\n");
			($palabra, $x)  = split / /, $palabra;
			print HAS ($palabra.  "\n");
			#print ("".$2.  "\n");
			#print ("".$3.  "\n");
		}
	}
	close (PAL);
	close (HAS);

	#Contador Hastag
	open(HAS,"+<hastag");

	my $archivo = 'hastag';
	open (FILE, $archivo);
	my @content = <FILE>;
	my @repe = "Hola";
	close(FILE);
	while ($line=<HAS>) { 
		chomp $line;
		my $i=0;
		foreach (@content) {
		     $i++ if ($_ =~ /$line/);  #palabra que deseas buscar
		}

		print "El hastag ".$line." ha sido encontrado ".$i." veces\n";
				
		
	}

	#BUSQUEDA NOMBRES 
	open(PAL,"+<log");
	open(NOM,">nombres");
	while ($line=<PAL>) { 
		chomp $line;
		#print $line . "\n";
		if ($line =~ /($NP)/g) {
			@NPS = $line =~ /($NP)/g;
			foreach (@NPS) {
		     		print NOM ($_ .   "\n");  
			}
			#print NOM (@NPS);
			#print ("".$2.  "\n");
			#print ("".$3.  "\n");
		}
	}
	close (PAL);
	close (NOM);

	#Contador Hastag
	open(NOM,"+<nombres");

	my $archivo = 'nombres';
	open (FILE, $archivo);
	my @content = <FILE>;
	close(FILE);
	while ($line=<NOM>) { 
		chomp $line;
		my $i=0;
		foreach (@content) {
		     $i++ if ($_ =~ /$line/);  #palabra que deseas buscar
		}

		print "El nombre ".$line." ha sido encontrado ".$i." veces\n";
				
		
	}










exit;

