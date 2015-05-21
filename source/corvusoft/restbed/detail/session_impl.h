/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _RESTBED_DETAIL_SESSION_IMPL_H
#define _RESTBED_DETAIL_SESSION_IMPL_H 1

//System Includes
#include <map>
#include <string>
#include <memory>
#include <istream>
#include <functional>

//Project Includes

//External Includes
#include <asio.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    class Request;
    class Session;
    
    namespace detail
    {
        //Forward Declarations
        
        class SessionImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                SessionImpl( void );
                
                virtual ~SessionImpl( void );
                
                //Functionality
                void fetch( const std::function< void ( const std::shared_ptr< Session >& ) >& callback, const std::shared_ptr< Session >& session );

//                bool is_open( void );
//
//                bool is_closed( void );
//
//                void close( void );
//
//                void close( const Response& value );
//
//                void close( uint16_t status_code );
//
//                void close( uint16_t status_code, Bytes& body );
//
//                void close( uint16_t status_code, multimap< string, string > headers, Bytes& body );
//
//                void yield( const Response& value ); //send response and call this function again with request.
//
//                void yield( const Response& value, const std::function< void ( const std::shared_ptr< Session >& ) >& callback );
//
//                void yield( uint16_t status_code, const std::function< void ( const std::shared_ptr< Session >& ) >& callback );
//
//                void yield( uint16_t status_code, Bytes& body, const std::function< void ( const std::shared_ptr< Session >& ) >& callback );
//
//                void yield( uint16_t status_code, multimap< string, string > headers, Bytes& body, const std::function< void ( const std::shared_ptr< Session >& ) >& callback );
//
//                void fetch( const std::function< void ( const std::shared_ptr< Session >& ) >& callback );
//
//                void fetch( const Request& value, const std::size_t length, const std::function< void ( const std::shared_ptr< Session >& ) >& read_callback );
//
//                void wait_for( const std::chrono::seconds& delay, const std::function< void ( const std::shared_ptr< Session >& ) >& expired_callback );
//
//                void wait_for( const std::chrono::seconds& delay, const std::size_t iterations, const std::function< void ( const std::shared_ptr< Session >& ) >& expired_callback );
//
//                void wait_for( const std::chrono::seconds& delay, const std::size_t iterations, const std::function< bool ( const std::shared_ptr< Session >& ) >& trigger, const std::function< void ( const std::shared_ptr< Session >& ) >& triggered_callback );

                //Getters
//                const Request& get_request( void ) const;
                const std::string& get_id( void ) const;

                //Setters
                void set_id( const std::string& value );

                void set_socket( const std::shared_ptr< asio::ip::tcp::socket >& value );
                
                //Operators
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                void set_request( const std::shared_ptr< Request >& value );
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                SessionImpl( const SessionImpl& original ) = delete;
                
                //Functionality
                static const std::multimap< std::string, std::string > parse_headers( std::istream& stream );

                static const std::map< std::string, std::string > parse_status_path_and_version( std::istream& stream );

                void parse_status_and_headers( const std::function< void ( const std::shared_ptr< Session >& ) >& callback,
                                               const std::shared_ptr< Session >& session,
                                               const asio::error_code& error );
                //Getters
                
                //Setters
                
                //Operators
                SessionImpl& operator =( const SessionImpl& value ) = delete;
                
                //Properties
                std::string m_id;

                std::shared_ptr< Request > m_request;

                std::shared_ptr< asio::streambuf > m_buffer;

                std::shared_ptr< asio::ip::tcp::socket > m_socket;
        };
    }
}

#endif  /* _RESTBED_DETAIL_SESSION_IMPL_H */
