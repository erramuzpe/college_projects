#!/usr/bin/perl
#use strict;
use CGI qw(param);
use utf8;
use XML::LibXML;
use Net::Twitter;
use LWP::Simple;
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



    $said = <STDIN>;
    #my $said = "Granada";
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


	#BUSQUEDA HASTAG
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
	print "CONTADOR HASTAG\n";
	open(HAS,"+<hastag");

	my $archivo = 'hastag';
	open (FILE, $archivo);
	my @content = <FILE>;
	close(FILE);

		#print "El hastag ".$line." ha sido encontrado ".$i." veces\n";

		while($line=<HAS>) {                           
   		 foreach (@content) {  
			$word = $_;
			$freq{$word}++ if ($word =~ /$line/);   
		    }
		}
		foreach $word (sort keys %freq) {        
			    print "$word $freq{$word}\n"; 
		}
		
		close (HAS);

	#BUSQUEDA NOMBRES 
	open(PAL,"+<log");
	open(NOM,">nombres");
	while ($line=<PAL>) { 
		chomp $line;
		#print $line . "\n";
		if ($line =~ /($NP)/g) {
			@NPS = $line =~ /($NP)/g;
			foreach (@NPS) {
				if (length($_) > 3){
		     			print NOM ($_ .   "\n");  
				}
			}
			#print NOM (@NPS);
			#print ("".$2.  "\n");
			#print ("".$3.  "\n");
		}
	}
	close (PAL);
	close (NOM);

	#Contador Nombres
	print "CONTADOR NOMBRES\n";
	open(NOM,"+<nombres");

	my $archivo = 'nombres';
	open (FILE, $archivo);
	my @content = <FILE>;
	close(FILE);

	while($line=<NOM>) {                           
   		 foreach (@content) {  
			$word2 = $_;
			$freq2{$word2}++ if ($word2 =~ /$line/);   
		    }
		}
		foreach $word2 (sort keys %freq2) {        
			    print "$word2 $freq2{$word2}\n"; 
		}
		
		
	close (NOM);

	#BUSCAR VERBOS Y ADJETIVOS
	open(VA,"+<log");
	while ($line=<VA>) { 
		#chomp $line;
		$texto = $texto.$line;
	}	
	#print $texto;
        #my $n= $texto =~ tr/ / /;
	#print $n;


		my $browser = LWP::UserAgent->new;
		my $response = $browser->post('http://cartago.lllf.uam.es/grampal/grampal.cgi',
                [
			'm' => 'xml',
			'fs' => 'xml',
			'texto' => 'Hola, esto es una frase de prueba muy bonita para comprobar que el programa funciona correctamente. Los twitts guardados en el largo fichero no funcionan bien y se ha escrito este gran texto para ver que funciona verde y largo.'
		],);
	#print $response->content;

	my $parser = XML::LibXML->new();
	my $doc = $parser->load_xml(string=>$response->content);

	my @link = $doc->findnodes('//contenido');
	foreach my $nodo (@link) {
	
		$Verbo = "cat=\"V\"";
		$Adj = "cat=\"ADJ\"";
		my @contenido = $nodo->findnodes('./p/f/w');
		foreach my $con(@contenido){
			$datos = $con->toString;
			
			if ($datos =~ m/$Verbo/i){
				
				if (exists($verbo{$con->to_literal})){
					#no se hace nada
				}	
				else{
					#se guarda 1 vez
					$verbos = $verbos.' '.$con->to_literal;
				}
			}
			elsif($datos =~ m/$Adj/i){
				
				if (exists($adj{$con->to_literal})){
					#no se hace nada
				}
				else{
					#se guarda 1 vez
					$adjetivos = $adjetivos.' '.$con->to_literal;
				}
			
		}
	}

}
close(VA);
print "Los verbos encontrados son: ".$verbos." \n";
print "Los adjetivos encontrados son: ".$adjetivos." \n";



exit;

