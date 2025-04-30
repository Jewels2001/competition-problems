import fileinput, itertools, math

g = {}
for l in fileinput.input():
    l = l.strip( '\n' ).replace( ",", "" ).replace( "rate=", "" ).replace( ";", "" ).split()
    g[ l[ 1 ] ] = ( int( l[ 4 ] ), { o: 1 for o in l[ 9 : ] } )

for k, i, j in itertools.product( g, g, g ):
    if ( i != j and j != k and k != i and
         k in g[ i ][ 1 ] and j in g[ k ][ 1 ] ):
        t = g[ i ][ 1 ][ k ] + g[ k ][ 1 ][ j ]
        if g[ i ][ 1 ].get( j, math.inf ) > t:
            g[ i ][ 1 ][ j ] = t

g = { kj: ( vj[ 0 ], { ki: vi for ki, vi in vj[ 1 ].items() if g[ ki ][ 0 ] } )
      for kj, vj in g.items() if vj[ 0 ] or kj == "AA" }
b = 0
def dfs( p, o, t, l, w ):
    global b
    b = max( b, p )
    print(b)
    for a, d in g[ l ][ 1 ].items():
        if a not in o and t + d + 1 < 30:
            dfs( p + ( 30 - t - d - 1 ) * g[ a ][ 0 ],
                 o | set( [ a ] ),
                 t + d + 1,
                 a,
                 w )
    print(l, a)
dfs( 0, set(), 0, "AA", 0 )
print( b )