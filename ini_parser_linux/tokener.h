#ifndef TOKENER_H_
#define TOKENER_H_

#include <assert.h>
#include <string.h>
#include <string>

namespace qh
{
    class Tokener
    {

    public:

        Tokener( const std::string& s );

		void reset(const char* ps, const int ps_len = -1);

        ~Tokener();
        /**
        * Get the characters up to the next character <code>quote</code>.
        * Backslash processing is done.
        * If <code>quote</code> is not found, we do nothing and just
        * return a string empty "".
        * @param quote The quoting character, either
        *      <code>"</code>(double quote) or
        *      <code>'</code>(single quote) or
        *      other character
        * @return the string
        */
        std::string nextString( char quote );

        /**
        * Get the characters up to the next white space( or tab, \n, \r, \0 ) character.
        *
        * @return the string
        */
        std::string nextString();
		 char next();
		  bool back();
        /**
        * Skip characters until the next character is the requested character.
        * If the requested character is not found, no characters are skipped.
        * @param to A character to skip to.
        * @return The requested character, or zero if the requested character
        * is not found.
        */
        char skipTo( char to );
		
        /** Gets current read position in the buffer. It also serve as length of buffer parsed. */
        int getCurPos() const
        {
            return m_pCurPos - m_pData;
        }

        /** Gets current read position in the buffer. */
        const char* getCurReadPos() const
        {
            return m_pCurPos;
        }

        /** Query whether it is the end of the string.*/
        bool isEnd() const
        {
            return ( m_pCurPos >= m_pDataEnd || *m_pCurPos == '\0' );
        }

        /** Gets size of data that can read from the current read position. */
        int getReadableSize() const
        {
            return (int)(m_pDataEnd - m_pCurPos);
        }       
    private:
        const char* m_pData;	//! the source text string to be parsed
        const char* m_pCurPos;  //! At first, set it 0
        const char* m_pDataEnd; //!
    };
	inline Tokener::Tokener( const std::string& s )
	{
		reset(s.c_str(), s.length());
	}
	inline void Tokener::reset( const char* ps, const int len )
	{
		m_pDataEnd = len + ps; 
		if ( len < 0 && ps )
		{
			m_pDataEnd = ps + strlen( ps );
		}

		m_pData   = const_cast<const char*>( ps );
		m_pCurPos = m_pData;
	}
	inline Tokener::~Tokener()
	{
	}
	//-------------------------------------

	inline bool Tokener::back()
	{
		if ( m_pCurPos <= m_pData )
		{
			fprintf(stderr, "Stepping back two steps is not supported\n" );
			return false;
		}

		--m_pCurPos;
		return true;
	}
	inline char Tokener::next()
	{
		if ( isEnd() )
		{
			//! End of string
			++m_pCurPos;
			return 0;
		}

		return *m_pCurPos++;
	}
	inline std::string Tokener::nextString()
	{
		if ( isEnd() )
		{
			return "";
		}

		const char* startpos = m_pCurPos;

		for ( unsigned char c = 0; m_pCurPos < m_pDataEnd; )
		{
			c = *m_pCurPos++;

			if (c <= ' ')
			{
				return std::string( startpos, m_pCurPos - startpos - 1);
			}

			if (isEnd())
			{
				return std::string( startpos, m_pDataEnd - startpos );
			}
		}

		assert(false && "Logic ERROR. The routine SHOULD NOT come there.");
		return std::string();
	}


	inline std::string Tokener::nextString( char quote )
	{
		const char* startpos = m_pCurPos;

		while ( *m_pCurPos++ != quote )
		{
			if ( isEnd() )
			{
				m_pCurPos = startpos;
				return std::string();
			}
		}

		assert( m_pCurPos > startpos );
		return std::string( startpos, m_pCurPos - startpos - 1 );
	}

	inline char Tokener::skipTo( char to )
	{
		register char c = 0;
		const char* startIndex = this->m_pCurPos;

		do
		{
			c = next();

			if ( c == 0 )
			{
				m_pCurPos = startIndex;
				return c;
			}
		}
		while ( c != to );

		back();
		return c;
	}

};//end of namespace qh

#endif // #ifdef _OSLIB_TOKENER_H_


