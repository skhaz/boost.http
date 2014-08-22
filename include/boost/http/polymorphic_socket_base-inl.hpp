/* Copyright (c) 2014 Vinícius dos Santos Oliveira

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) */

namespace boost {
namespace http {

inline polymorphic_socket_base::~polymorphic_socket_base() = default;

template<class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
polymorphic_socket_base
::async_read_some(message &message, CompletionToken &&token)
{
    typedef typename asio::handler_type<
        CompletionToken, void(system::error_code)>::type Handler;

    Handler handler(std::forward<CompletionToken>(token));

    asio::async_result<Handler> result(handler);

    async_read_some(message, callback_type(handler));

    return result.get();
}

template<class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
polymorphic_socket_base
::async_read_trailers(message &message, CompletionToken &&token)
{
    typedef typename asio::handler_type<
        CompletionToken, void(system::error_code)>::type Handler;

    Handler handler(std::forward<CompletionToken>(token));

    asio::async_result<Handler> result(handler);

    async_read_trailers(message, callback_type(handler));

    return result.get();
}

template<class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
polymorphic_socket_base
::async_write(const message &message, CompletionToken &&token)
{
    typedef typename asio::handler_type<
        CompletionToken, void(system::error_code)>::type Handler;

    Handler handler(std::forward<CompletionToken>(token));

    asio::async_result<Handler> result(handler);

    async_write(message, callback_type(handler));

    return result.get();
}

template<class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
polymorphic_socket_base
::async_write_trailers(const message &message, CompletionToken &&token)
{
    typedef typename asio::handler_type<
        CompletionToken, void(system::error_code)>::type Handler;

    Handler handler(std::forward<CompletionToken>(token));

    asio::async_result<Handler> result(handler);

    async_write_trailers(message, callback_type(handler));

    return result.get();
}

template<class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
polymorphic_socket_base
::async_write_end_of_message(CompletionToken &&token)
{
    typedef typename asio::handler_type<
        CompletionToken, void(system::error_code)>::type Handler;

    Handler handler(std::forward<CompletionToken>(token));

    asio::async_result<Handler> result(handler);

    async_write_end_of_message(callback_type(handler));

    return result.get();
}

} // namespace http
} // namespace boost
