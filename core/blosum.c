#define DEFAULTGOP_B -1530
#define DEFAULTGEP_B   -00 
#define DEFAULTOFS_B  -123   /* +10 -- -50  teido ka ? */


void BLOSUMmtx( int n, double **matrix, double *freq, unsigned char *amino, char *amino_grp )
{
	/*
	char locaminod[26] = "GASTPLIMVDNEQFYWKRHCXXX.-U";
	*/
//	char locaminod[] = "ARNDCQEGHILKMFPSTWYVBZX.-U";
	char locaminod[] = "ARNDCQEGHILKMFPSTWYVBZX.-J";
	char locgrpd[] = 
	{
		0, 3, 2, 2, 5, 2, 2, 0, 3, 1, 1, 3, 1, 4, 0, 0, 0, 4, 4, 1, 2, 2,
		6, 6, 6, 1,
	};
	double freqd[20] = 
	{
	    0.077,
	    0.051,
	    0.043,
	    0.052,
	    0.020,
	    0.041,
	    0.062,
	    0.074,
	    0.023,
	    0.052,
	    0.091,
	    0.059,
	    0.024,
	    0.040,
	    0.051,
	    0.069,
	    0.059,
	    0.014,
	    0.032,
	    0.066,
	};

	double tmpmtx30[] = 
	{
    4,
   -1,     8,
    0,    -2,     8,
    0,    -1,     1,     9,
   -3,    -2,    -1,    -3,    17,
    1,     3,    -1,    -1,    -2,     8,
    0,    -1,    -1,     1,     1,     2,     6,
    0,    -2,     0,    -1,    -4,    -2,    -2,     8,
   -2,    -1,    -1,    -2,    -5,     0,     0,    -3,    14,
    0,    -3,     0,    -4,    -2,    -2,    -3,    -1,    -2,     6,
   -1,    -2,    -2,    -1,     0,    -2,    -1,    -2,    -1,     2,     4,
    0,     1,     0,     0,    -3,     0,     2,    -1,    -2,    -2,    -2,     4,
    1,     0,     0,    -3,    -2,    -1,    -1,    -2,     2,     1,     2,     2,     6,
   -2,    -1,    -1,    -5,    -3,    -3,    -4,    -3,    -3,     0,     2,    -1,    -2,    10,
   -1,    -1,    -3,    -1,    -3,     0,     1,    -1,     1,    -3,    -3,     1,    -4,    -4,    11,
    1,    -1,     0,     0,    -2,    -1,     0,     0,    -1,    -1,    -2,     0,    -2,    -1,    -1,     4,
    1,    -3,     1,    -1,    -2,     0,    -2,    -2,    -2,     0,     0,    -1,     0,    -2,     0,     2,     5,
   -5,     0,    -7,    -4,    -2,    -1,    -1,     1,    -5,    -3,    -2,    -2,    -3,     1,    -3,    -3,    -5,    20,
   -4,     0,    -4,    -1,    -6,    -1,    -2,    -3,     0,    -1,     3,    -1,    -1,     3,    -2,    -2,    -1,     5,     9,
    1,    -1,    -2,    -2,    -2,    -3,    -3,    -3,    -3,     4,     1,    -2,     0,     1,    -4,    -1,     1,    -3,     1,     5,
    0,    -2,     4,     5,    -2,    -1,     0,     0,    -2,    -2,    -1,     0,    -2,    -3,    -2,     0,     0,    -5,    -3,    -2,     5,
    0,     0,    -1,     0,     0,     4,     5,    -2,     0,    -3,    -1,     1,    -1,    -4,     0,    -1,    -1,    -1,    -2,    -3,     0,     4,
    0,    -1,     0,    -1,    -2,     0,    -1,    -1,    -1,     0,     0,     0,     0,    -1,    -1,     0,     0,    -2,    -1,     0,    -1,     0,    -1,
	};
	
	double tmpmtx45[] = 
	{
      5,
     -2,      7,
     -1,      0,      6,
     -2,     -1,      2,      7,
     -1,     -3,     -2,     -3,     12,
     -1,      1,      0,      0,     -3,      6,
     -1,      0,      0,      2,     -3,      2,      6,
      0,     -2,      0,     -1,     -3,     -2,     -2,      7,
     -2,      0,      1,      0,     -3,      1,      0,     -2,     10,
     -1,     -3,     -2,     -4,     -3,     -2,     -3,     -4,     -3,      5,
     -1,     -2,     -3,     -3,     -2,     -2,     -2,     -3,     -2,      2,      5,
     -1,      3,      0,      0,     -3,      1,      1,     -2,     -1,     -3,     -3,      5,
     -1,     -1,     -2,     -3,     -2,      0,     -2,     -2,      0,      2,      2,     -1,      6,
     -2,     -2,     -2,     -4,     -2,     -4,     -3,     -3,     -2,      0,      1,     -3,      0,      8,
     -1,     -2,     -2,     -1,     -4,     -1,      0,     -2,     -2,     -2,     -3,     -1,     -2,     -3,      9,
      1,     -1,      1,      0,     -1,      0,      0,      0,     -1,     -2,     -3,     -1,     -2,     -2,     -1,      4,
      0,     -1,      0,     -1,     -1,     -1,     -1,     -2,     -2,     -1,     -1,     -1,     -1,     -1,     -1,      2,      5,
     -2,     -2,     -4,     -4,     -5,     -2,     -3,     -2,     -3,     -2,     -2,     -2,     -2,      1,     -3,     -4,     -3,     15,
     -2,     -1,     -2,     -2,     -3,     -1,     -2,     -3,      2,      0,      0,     -1,      0,      3,     -3,     -2,     -1,      3,      8,
      0,     -2,     -3,     -3,     -1,     -3,     -3,     -3,     -3,      3,      1,     -2,      1,      0,     -3,     -1,      0,     -3,     -1,      5,
	};
    double tmpmtx50[] = 
    {
       5,
      -2,      7,
      -1,     -1,      7,
      -2,     -2,      2,      8,
      -1,     -4,     -2,     -4,     13,
      -1,      1,      0,      0,     -3,      7,
      -1,      0,      0,      2,     -3,      2,      6,
       0,     -3,      0,     -1,     -3,     -2,     -3,      8,
      -2,      0,      1,     -1,     -3,      1,      0,     -2,     10,
      -1,     -4,     -3,     -4,     -2,     -3,     -4,     -4,     -4,      5,
      -2,     -3,     -4,     -4,     -2,     -2,     -3,     -4,     -3,      2,      5,
      -1,      3,      0,     -1,     -3,      2,      1,     -2,      0,     -3,     -3,      6,
      -1,     -2,     -2,     -4,     -2,      0,     -2,     -3,     -1,      2,      3,     -2,      7,
      -3,     -3,     -4,     -5,     -2,     -4,     -3,     -4,     -1,      0,      1,     -4,      0,      8,
      -1,     -3,     -2,     -1,     -4,     -1,     -1,     -2,     -2,     -3,     -4,     -1,     -3,     -4,     10,
       1,     -1,      1,      0,     -1,      0,     -1,      0,     -1,     -3,     -3,      0,     -2,     -3,     -1,      5,
       0,     -1,      0,     -1,     -1,     -1,     -1,     -2,     -2,     -1,     -1,     -1,     -1,     -2,     -1,      2,      5,
      -3,     -3,     -4,     -5,     -5,     -1,     -3,     -3,     -3,     -3,     -2,     -3,     -1,      1,     -4,     -4,     -3,     15,
      -2,     -1,     -2,     -3,     -3,     -1,     -2,     -3,      2,     -1,     -1,     -2,      0,      4,     -3,     -2,     -2,      2,      8,
       0,     -3,     -3,     -4,     -1,     -3,     -3,     -4,     -4,      4,      1,     -3,      1,     -1,     -3,     -2,      0,     -3,     -1,      5,
    };
	double tmpmtx62[] = 
	{
      6,
     -2,      8,
     -2,     -1,      8,
     -3,     -2,      2,      9,
     -1,     -5,     -4,     -5,     13,
     -1,      1,      0,      0,     -4,      8,
     -1,      0,      0,      2,     -5,      3,      7,
      0,     -3,     -1,     -2,     -4,     -3,     -3,      8,
     -2,      0,      1,     -2,     -4,      1,      0,     -3,     11,
     -2,     -4,     -5,     -5,     -2,     -4,     -5,     -6,     -5,      6,
     -2,     -3,     -5,     -5,     -2,     -3,     -4,     -5,     -4,      2,      6,
     -1,      3,      0,     -1,     -5,      2,      1,     -2,     -1,     -4,     -4,      7,
     -1,     -2,     -3,     -5,     -2,     -1,     -3,     -4,     -2,      2,      3,     -2,      8,
     -3,     -4,     -4,     -5,     -4,     -5,     -5,     -5,     -2,      0,      1,     -5,      0,      9,
     -1,     -3,     -3,     -2,     -4,     -2,     -2,     -3,     -3,     -4,     -4,     -2,     -4,     -5,     11,
      2,     -1,      1,      0,     -1,      0,      0,      0,     -1,     -4,     -4,      0,     -2,     -4,     -1,      6,
      0,     -2,      0,     -2,     -1,     -1,     -1,     -2,     -3,     -1,     -2,     -1,     -1,     -3,     -2,      2,      7,
     -4,     -4,     -6,     -6,     -3,     -3,     -4,     -4,     -4,     -4,     -2,     -4,     -2,      1,     -5,     -4,     -4,     16,
     -3,     -3,     -3,     -5,     -4,     -2,     -3,     -5,      3,     -2,     -2,     -3,     -1,      4,     -4,     -3,     -2,      3,     10,
      0,     -4,     -4,     -5,     -1,     -3,     -4,     -5,     -5,      4,      1,     -3,      1,     -1,     -4,     -2,      0,     -4,     -2,      6,
	};
	double tmpmtx80[] = 
	{
      7,
     -3,      9,
     -3,     -1,      9,
     -3,     -3,      2,     10,
     -1,     -6,     -5,     -7,     13,
     -2,      1,      0,     -1,     -5,      9,
     -2,     -1,     -1,      2,     -7,      3,      8,
      0,     -4,     -1,     -3,     -6,     -4,     -4,      9,
     -3,      0,      1,     -2,     -7,      1,      0,     -4,     12,
     -3,     -5,     -6,     -7,     -2,     -5,     -6,     -7,     -6,      7,
     -3,     -4,     -6,     -7,     -3,     -4,     -6,     -7,     -5,      2,      6,
     -1,      3,      0,     -2,     -6,      2,      1,     -3,     -1,     -5,     -4,      8,
     -2,     -3,     -4,     -6,     -3,     -1,     -4,     -5,     -4,      2,      3,     -3,      9,
     -4,     -5,     -6,     -6,     -4,     -5,     -6,     -6,     -2,     -1,      0,     -5,      0,     10,
     -1,     -3,     -4,     -3,     -6,     -3,     -2,     -5,     -4,     -5,     -5,     -2,     -4,     -6,     12,
      2,     -2,      1,     -1,     -2,     -1,     -1,     -1,     -2,     -4,     -4,     -1,     -3,     -4,     -2,      7,
      0,     -2,      0,     -2,     -2,     -1,     -2,     -3,     -3,     -2,     -3,     -1,     -1,     -4,     -3,      2,      8,
     -5,     -5,     -7,     -8,     -5,     -4,     -6,     -6,     -4,     -5,     -4,     -6,     -3,      0,     -7,     -6,     -5,     16,
     -4,     -4,     -4,     -6,     -5,     -3,     -5,     -6,      3,     -3,     -2,     -4,     -3,      4,     -6,     -3,     -3,      3,     11,
     -1,     -4,     -5,     -6,     -2,     -4,     -4,     -6,     -5,      4,      1,     -4,      1,     -2,     -4,     -3,      0,     -5,     -3,      7,
	};
	double tmpmtx90[] = 
	{
 5,
-2,  6,
-2, -1,  7,
-3, -3,  1,  7,
-1, -5, -4, -5,  9,
-1,  1,  0, -1, -4,  7,
-1, -1, -1,  1, -6,  2,  6,
 0, -3, -1, -2, -4, -3, -3,  6,
-2,  0,  0, -2, -5,  1, -1, -3,  8,
-2, -4, -4, -5, -2, -4, -4, -5, -4,  5,
-2, -3, -4, -5, -2, -3, -4, -5, -4,  1,  5,
-1,  2,  0, -1, -4,  1,  0, -2, -1, -4, -3,  6,
-2, -2, -3, -4, -2,  0, -3, -4, -3,  1,  2, -2,  7,
-3, -4, -4, -5, -3, -4, -5, -5, -2, -1,  0, -4, -1,  7,
-1, -3, -3, -3, -4, -2, -2, -3, -3, -4, -4, -2, -3, -4,  8,
 1, -1,  0, -1, -2, -1, -1, -1, -2, -3, -3, -1, -2, -3, -2,  5,
 0, -2,  0, -2, -2, -1, -1, -3, -2, -1, -2, -1, -1, -3, -2,  1,  6,
-4, -4, -5, -6, -4, -3, -5, -4, -3, -4, -3, -5, -2,  0, -5, -4, -4, 11,
-3, -3, -3, -4, -4, -3, -4, -5,  1, -2, -2, -3, -2,  3, -4, -3, -2,  2,  8,
-1, -3, -4, -5, -2, -3, -3, -5, -4,  3,  0, -3,  0, -2, -3, -2, -1, -3, -3,  5,
	};
	double tmpmtx100[] = 
	{
 8,
-3,10,
-4,-2,11,
-5,-5, 1,10,
-2,-8,-5,-8,14,
-2, 0,-1,-2,-7,11,
-3,-2,-2, 2,-9, 2,10,
-1,-6,-2,-4,-7,-5,-6, 9,
-4,-1, 0,-3,-8, 1,-2,-6,13,
-4,-7,-7,-8,-3,-6,-7,-9,-7, 8,
-4,-6,-7,-8,-5,-5,-7,-8,-6, 2, 8,
-2, 3,-1,-3,-8, 2, 0,-5,-3,-6,-6,10,
-3,-4,-5,-8,-4,-2,-5,-7,-5, 1, 3,-4,12,
-5,-6,-7,-8,-4,-6,-8,-8,-4,-2, 0,-6,-1,11,
-2,-5,-5,-5,-8,-4,-4,-6,-5,-7,-7,-3,-5,-7,12,
 1,-3, 0,-2,-3,-2,-2,-2,-3,-5,-6,-2,-4,-5,-3, 9,
-1,-3,-1,-4,-3,-3,-3,-5,-4,-3,-4,-3,-2,-5,-4, 2, 9,
-6,-7,-8,-10,-7,-5,-8,-7,-5,-6,-5,-8,-4, 0,-8,-7,-7,17,
-5,-5,-5,-7,-6,-4,-7,-8, 1,-4,-4,-5,-5, 4,-7,-5,-5, 2,12,
-2,-6,-7,-8,-3,-5,-5,-8,-7, 4, 0,-5, 0,-3,-6,-4,-1,-5,-5, 8,
	};
	double tmpmtx0[] = 
	{
     2.4,
    -0.6,    4.7,
    -0.3,    0.3,    3.8,
    -0.3,   -0.3,    2.2,    4.7,
     0.5,   -2.2,   -1.8,   -3.2,   11.5,
    -0.2,    1.5,    0.7,    0.9,   -2.4,    2.7,
     0.0,    0.4,    0.9,    2.7,   -3.0,    1.7,    3.6,
     0.5,   -1.0,    0.4,    0.1,   -2.0,   -1.0,   -0.8,    6.6,
    -0.8,    0.6,    1.2,    0.4,   -1.3,    1.2,    0.4,   -1.4,    6.0,
    -0.8,   -2.4,   -2.8,   -3.8,   -1.1,   -1.9,   -2.7,   -4.5,   -2.2,    4.0,
    -1.2,   -2.2,   -3.0,   -4.0,   -1.5,   -1.6,   -2.8,   -4.4,   -1.9,    2.8,    4.0,
    -0.4,    2.7,    0.8,    0.5,   -2.8,    1.5,    1.2,   -1.1,    0.6,   -2.1,   -2.1,    3.2,
    -0.7,   -1.7,   -2.2,   -3.0,   -0.9,   -1.0,   -2.0,   -3.5,   -1.3,    2.5,    2.8,   -1.4,    4.3,
    -2.3,   -3.2,   -3.1,   -4.5,   -0.8,   -2.6,   -3.9,   -5.2,   -0.1,    1.0,    2.0,   -3.3,    1.6,    7.0,
     0.3,   -0.9,   -0.9,   -0.7,   -3.1,   -0.2,   -0.5,   -1.6,   -1.1,   -2.6,   -2.3,   -0.6,   -2.4,   -3.8,    7.6,
     1.1,   -0.2,    0.9,    0.5,    0.1,    0.2,    0.2,    0.4,   -0.2,   -1.8,   -2.1,    0.1,   -1.4,   -2.8,    0.4,    2.2,
     0.6,   -0.2,    0.5,    0.0,   -0.5,    0.0,   -0.1,   -1.1,   -0.3,   -0.6,   -1.3,    0.1,   -0.6,   -2.2,    0.1,    1.5,    2.5,
    -3.6,   -1.6,   -3.6,   -5.2,   -1.0,   -2.7,   -4.3,   -4.0,   -0.8,   -1.8,   -0.7,   -3.5,   -1.0,    3.6,   -5.0,   -3.3,   -3.5,   14.2,
    -2.2,   -1.8,   -1.4,   -2.8,   -0.5,   -1.7,   -2.7,   -4.0,    2.2,   -0.7,    0.0,   -2.1,   -0.2,    5.1,   -3.1,   -1.9,   -1.9,    4.1,    7.8,
     0.1,   -2.0,   -2.2,   -2.9,    0.0,   -1.5,   -1.9,   -3.3,   -2.0,    3.1,    1.8,   -1.7,    1.6,    0.1,   -1.8,   -1.0,    0.0,   -2.6,   -1.1,    3.4,
	};

	int i, j, count;
	double av;
	double *tmpmtx;

	if( n == 30 ) tmpmtx = tmpmtx30;
	else if( n == 45 ) tmpmtx = tmpmtx45;
	else if( n == 50 ) tmpmtx = tmpmtx50;
	else if( n == 62 ) tmpmtx = tmpmtx62;
	else if( n == 80 ) tmpmtx = tmpmtx80;
	else if( n == 90 ) tmpmtx = tmpmtx90;
	else if( n == 100 ) tmpmtx = tmpmtx100;
	else if( n == 0 ) tmpmtx = tmpmtx0;
	else if( n == -1 ) tmpmtx = loadaamtx();
	else
	{
		fprintf( stderr, "blosum %d ?\n", n );
		exit( 1 );
	}

	count = 0;
	for( i=0; i<20; i++ )
	{
		for( j=0; j<=i; j++ )
		{
			matrix[i][j] = matrix[j][i] = (double)tmpmtx[count++];
		}
	}
	if( n == -1 && tmpmtx[400] != -1.0 ) 
	{
		for( i=0; i<20; i++ ) freq[i] = tmpmtx[400+i];
		av = 0.0;
		for( i=0; i<20; i++ ) av += freq[i];
		for( i=0; i<20; i++ ) freq[i] /= av;
	}
	else
		for( i=0; i<20; i++ ) freq[i] = freqd[i];

#if 0
	av = 0.0;
	for( i=0; i<20; i++ )
		av += matrix[i][i];
	av /= 20;
	fprintf( stdout, "av = %f\n", av );

	for( i=0; i<20; i++ ) for( j=0; j<20; j++ )
		matrix[i][j] /= av;

	av = wav = 0;
	count = 0;
	wcount = 0.0;
	tmptmp = 0.0;
	for( i=0; i<20; i++ )
	{
		fprintf( stdout, "freq[%d] = %f\n", i, freq[i] );
		tmptmp += freq[i];
		for( j=0; j<20; j++ )
		{
			av += matrix[i][j];
			wav += freq[i] * freq[j] * matrix[i][j];
			count++;
			wcount += freq[i] * freq[j];
		}
	}

	av /= count;
	wav /= wcount;
	fprintf( stdout, "av = %f\n", av );
	fprintf( stdout, "wav = %f\n", wav );
	fprintf( stdout, "wcount = %f\n", wcount );
	fprintf( stdout, "tmptmp = %f\n", tmptmp );

	for( i=0; i<20; i++ )
	{
		for( j=0; j<=i; j++ )
		{
			fprintf( stderr, "## %d-%d, %f\n", i, j, matrix[i][j] );
		}
	}

	exit( 1 );
#endif

    for( i=0; i<26; i++ ) amino[i] = locaminod[i];
    for( i=0; i<26; i++ ) amino_grp[(int)amino[i]] = locgrpd[i];
}

void extendedmtx( double **matrix, double *freq, unsigned char *amino, char *amino_grp )
{
	int i;
	int j;

	for( i=0; i<nalphabets; i++ ) 
	{
//		fprintf( stderr, "i=%d, i=%c\n", i, i );
		amino[i] = (unsigned char)i;
	}
	for( i=0; i<nalphabets; i++ ) amino_grp[(int)amino[i]] = i % 6;
	for( i=0; i<nalphabets; i++ ) freq[i] = 1.0/nalphabets;

	for( i=0; i<nalphabets; i++ )
	{
		for( j=0; j<=i; j++ )
		{
			matrix[i][j] = matrix[j][i] = (double)-1.0;
		}
	}
	for( i=0; i<nalphabets; i++ )
		matrix[i][i] = matrix[i][i] = (double)1.0;
#if 0 // user-defined matrix no toki fukkatsu saseru.
	if( tmpmtx[400] != -1.0 ) 
	{
		for( i=0; i<20; i++ ) freq[i] = tmpmtx[400+i];
		av = 0.0;
		for( i=0; i<20; i++ ) av += freq[i];
		for( i=0; i<20; i++ ) freq[i] /= av;
	}
	else
		for( i=0; i<20; i++ ) freq[i] = freqd[i];
#endif
#if 0
	for( i=0; i<nalphabets; i++ )
	{
		fprintf( stderr, "%d: %c, %d, %f\n", i, amino[i], amino_grp[amino[i]], freq[i] );
	}
#endif
}
