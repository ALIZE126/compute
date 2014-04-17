//---------------------------------------------------------------------------//
// Copyright (c) 2013-2014 Kyle Lutz <kyle.r.lutz@gmail.com>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
// See http://kylelutz.github.com/compute for more information.
//---------------------------------------------------------------------------//

#ifndef BOOST_COMPUTE_USER_EVENT_HPP
#define BOOST_COMPUTE_USER_EVENT_HPP

#include <boost/compute/event.hpp>
#include <boost/compute/context.hpp>

namespace boost {
namespace compute {

#if defined(CL_VERSION_1_1) || defined(BOOST_COMPUTE_DOXYGEN_INVOKED)
/// \class user_event
/// \brief An user-created event.
///
/// \opencl_version_warning{1,1}
///
/// \see event
class user_event : public event
{
public:
    /// Creates a new user-event object.
    ///
    /// \see_opencl_ref{clCreateUserEvent}
    explicit user_event(const context &context)
    {
        cl_int error;
        m_event = clCreateUserEvent(context.get(), &error);
        if(!m_event){
            BOOST_THROW_EXCEPTION(runtime_exception(error));
        }
    }

    /// Creates a new user-event from \p other.
    user_event(const user_event &other)
        : event(other)
    {
    }

    /// Copies the user-event from \p other to \c *this.
    user_event& operator=(const user_event &other)
    {
        event::operator=(other);

        return *this;
    }

    /// Sets the execution status for the user-event.
    ///
    /// \see_opencl_ref{clSetUserEventStatus}
    void set_status(cl_int execution_status)
    {
        cl_int ret = clSetUserEventStatus(m_event, execution_status);
        if(ret != CL_SUCCESS){
            BOOST_THROW_EXCEPTION(runtime_exception(ret));
        }
    }
};
#endif // CL_VERSION_1_1

} // end compute namespace
} // end boost namespace

#endif // BOOST_COMPUTE_EVENT_HPP
