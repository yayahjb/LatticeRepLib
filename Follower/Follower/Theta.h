
#ifndef THETA_H
#define THETA_H

#include <valarray>

class CThetaSizeError
{
};

template < typename T >
class ThetaMatch
{
public:

//=================================================================
   ThetaMatch ( )
   {
      m_lMaxCharacter = 256;
      m_wf.resize( m_lMaxCharacter, 1.0 );
      m_wr.resize( m_lMaxCharacter, 0.8 );
      m_wc.resize( m_lMaxCharacter, 0.0 );
      m_bDoCompensation = false;
   };

//=================================================================
   ThetaMatch ( const size_t lMaxCharacter )
   {
      m_lMaxCharacter = lMaxCharacter;
      m_wf.resize( m_lMaxCharacter, 1.0 );
      m_wr.resize( m_lMaxCharacter, 0.8 );
      m_wc.resize( m_lMaxCharacter, 0.0 );
      m_bDoCompensation = false;
   };

//=================================================================
   ThetaMatch ( const std::valarray<T> vForwardWeights,
      const std::valarray<T> vReverseWeights )
   {
      m_lMaxCharacter = vForwardWeights.size( );
      m_wf = vForwardWeights;
      m_wr = vReverseWeights;
      m_wc.resize( m_lMaxCharacter, 0.0 );
      m_bDoCompensation = false;
   };

//=================================================================
   double operator ( ) ( const T& s, const T& t ) const
   {
      if ( s == t )
         return ( 0.0 );
      else
         return ( theta( s, t ) );
   };

//=================================================================
   void SetThetaWeights ( const std::valarray<double>& wf,
      const std::valarray<double>& wr )
   {
      if ( wf.size( ) != m_lMaxCharacter ) throw CThetaSizeError( );
      if ( wr.size( ) != m_lMaxCharacter ) throw CThetaSizeError( );
      m_wf = wf;
      m_wr = wr;
   };

//=================================================================
   void SetThetaWeights ( const double& wf, const double& wr )
   {
      m_wf = wf;
      m_wr = wr;
   };

//=================================================================
   double theta (const T& s, const T& t ) const
   {
      const double dTemp = totalM( s ) + totalM( t );
      if ( dTemp == 0.0 )
         return ( 1.0 );
      else
         return ( 1.0-
            (( m(s, t, 1, m_wf ) + m( s, t, -1, m_wr ) ) / dTemp ));
   };

//=================================================================
private:
   std::valarray<double> m_wf ;
   std::valarray<double> m_wr ;
   std::valarray<double> m_wc ;
   size_t m_lMaxCharacter;
   bool m_bDoCompensation;

//=================================================================
   double totalM ( const T& x ) const
   {
      size_t lParticularCharacter;
      double dReturn = 0;
      const size_t lLengthOfString = (size_t)x.length( );

      for ( size_t i=0; i<lLengthOfString; ++i )
      {
         lParticularCharacter = static_cast<long> (x[i] );
         dReturn += ( lLengthOfString - i ) *
            m_wf[ lParticularCharacter ] +
            ( i + 1 ) * m_wr[ lParticularCharacter ];
      }
      return ( dReturn );
   };

//=================================================================
   double m( const T& s, const T& t, const int& direction,
      const std::valarray<double>& w ) const
   // this code could probably get into trouble if characters are 
   // signed char
   {  
       double sum = 0.0;
       size_t i;
       const long lIncrement = ( direction>0 ? 1 : -1 );

       std::valarray<size_t> cnts ( m_lMaxCharacter );
       std::valarray<size_t> cntt ( m_lMaxCharacter );
       cnts = 0;
       cntt = 0;

       long lpts = ( lIncrement < 1 ? (long)s.length( ) : -1L );
       long lptt = ( lIncrement < 1 ? (long)t.length( ) : -1L );
       long s_count = (long)s.length( ) + 1;
       long t_count = (long)t.length( ) + 1;
       size_t s_char = 0;
       size_t t_char = 0;

       //cout << endl << endl;
       //cout << " increment " << direction << endl;
       //cout << " s \"" << s << "\"  t \"" << t << "\"" << endl;
       //cout << " i \t lpts \t lptt \t s_count  t_count " << endl;
       for ( i=0; i<std::max( s.length( ), t.length( ) ); i++ )
       {
           lpts += lIncrement;
           lptt += lIncrement;
           s_count = std::max( s_count-1, 0L );
           t_count = std::max( t_count-1, 0L );
           //cout << i << " \t" << lpts << " \t" << lptt 
           //       << " \t" << s_count << " \t" << t_count << endl;
           if ( s_count > 0 )
           {
               s_char = static_cast<size_t> ( s[lpts] );
               cnts[s_char] += 1;
           }
           if ( t_count > 0)
           {
               t_char = static_cast<size_t> ( t[lptt] );
               cntt[t_char] += 1;
           }
           if ( ( s_count > 0 ) && ( t_count > 0 ) && 
              ( s_char == t_char ))
               sum += w[s_char] * ( s_count+t_count );
           else
           {
               if ( ( s_count > 0 ) && ( cnts[s_char] <= cntt[s_char] ))
                   sum += w[s_char] * ( s_count+t_count );
               if ( ( t_count > 0 ) && ( cntt[t_char] <= cnts[t_char] ))
                   sum += w[t_char] * ( s_count+t_count ) ;
           }
       }
       //  only do compensation once (if at all) !
       //if ( m_bDoCompensation && direction > 0 )  
       //   sum += + compensation( lpts, lptt, cnts, cntt );   // LCA find the code !!!!!!!!!
       return ( sum );
   };

}; // template class ThetaMatch

#endif // THETA_H