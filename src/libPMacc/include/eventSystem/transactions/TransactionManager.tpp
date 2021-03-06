/**
 * Copyright 2013 Felix Schmitt, Rene Widera
 *
 * This file is part of libPMacc. 
 * 
 * libPMacc is free software: you can redistribute it and/or modify 
 * it under the terms of of either the GNU General Public License or 
 * the GNU Lesser General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version. 
 * libPMacc is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License and the GNU Lesser General Public License 
 * for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * and the GNU Lesser General Public License along with libPMacc. 
 * If not, see <http://www.gnu.org/licenses/>. 
 */ 
 
#include <cassert>
#include "eventSystem/EventSystem.hpp"

namespace PMacc
{

inline TransactionManager::~TransactionManager( )
{
    if ( !transactions.size( ) > 1 )
        throw std::runtime_error( "Unfinished transactions on the stack" );
    transactions.pop( );
}

inline TransactionManager::TransactionManager( )
{
    startTransaction( EventTask( ) );
}

inline TransactionManager::TransactionManager( const TransactionManager& )
{

}

inline void TransactionManager::startTransaction( EventTask serialEvent )
{
    transactions.push( Transaction( serialEvent,false ) );
}

inline void TransactionManager::startAtomicTransaction( EventTask serialEvent )
{
    transactions.push( Transaction( serialEvent, true ) );
}

inline EventTask TransactionManager::endTransaction( )
{
    if ( transactions.size( ) == 0 )
        throw std::runtime_error( "Calling endTransaction on empty transaction stack is not allowed" );

    EventTask event = transactions.top( ).getTransactionEvent( );
    transactions.pop( );
    return event;
}

inline void TransactionManager::startOperation( ITask::TaskType op )
{
    if ( transactions.size( ) == 0 )
        throw std::runtime_error( "Calling startOperation on empty transaction stack is not allowed" );

    transactions.top( ).operation( op );
}

inline EventStream *TransactionManager::getEventStream( ITask::TaskType op )
{
    if ( transactions.size( ) == 0 )
        throw std::runtime_error( "Calling startOperation on empty transaction stack is not allowed" );

    return transactions.top( ).getEventStream( op );
}

inline EventTask TransactionManager::setTransactionEvent( const EventTask& event )
{
    if ( transactions.size( ) == 0 )
        throw std::runtime_error( "Calling setTransactionEvent on empty transaction stack is not allowed" );

    return transactions.top( ).setTransactionEvent( event );
}

inline EventTask TransactionManager::getTransactionEvent( )
{
    if ( transactions.size( ) == 0 )
        throw std::runtime_error( "Calling getTransactionEvent on empty transaction stack is not allowed" );

    return transactions.top( ).getTransactionEvent( );
}

inline TransactionManager& TransactionManager::getInstance( )
{
    static TransactionManager instance;
    return instance;
}

}
