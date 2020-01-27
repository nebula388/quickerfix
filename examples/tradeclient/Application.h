/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) 2001-2014
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifndef TRADECLIENT_APPLICATION_H
#define TRADECLIENT_APPLICATION_H

#include "Application.h"
#include "MessageCracker.h"
#include "Values.h"
#include "Mutex.h"

#include "fix40/NewOrderSingle.h"
#include "fix40/ExecutionReport.h"
#include "fix40/OrderCancelRequest.h"
#include "fix40/OrderCancelReject.h"
#include "fix40/OrderCancelReplaceRequest.h"

#include "fix41/NewOrderSingle.h"
#include "fix41/ExecutionReport.h"
#include "fix41/OrderCancelRequest.h"
#include "fix41/OrderCancelReject.h"
#include "fix41/OrderCancelReplaceRequest.h"

#include "fix42/NewOrderSingle.h"
#include "fix42/ExecutionReport.h"
#include "fix42/OrderCancelRequest.h"
#include "fix42/OrderCancelReject.h"
#include "fix42/OrderCancelReplaceRequest.h"

#include "fix43/NewOrderSingle.h"
#include "fix43/ExecutionReport.h"
#include "fix43/OrderCancelRequest.h"
#include "fix43/OrderCancelReject.h"
#include "fix43/OrderCancelReplaceRequest.h"
#include "fix43/MarketDataRequest.h"

#include "fix44/NewOrderSingle.h"
#include "fix44/ExecutionReport.h"
#include "fix44/OrderCancelRequest.h"
#include "fix44/OrderCancelReject.h"
#include "fix44/OrderCancelReplaceRequest.h"
#include "fix44/MarketDataRequest.h"

#include "fix50/NewOrderSingle.h"
#include "fix50/ExecutionReport.h"
#include "fix50/OrderCancelRequest.h"
#include "fix50/OrderCancelReject.h"
#include "fix50/OrderCancelReplaceRequest.h"
#include "fix50/MarketDataRequest.h"

#include <queue>

class Application :
      public FIX::Application,
      public FIX::MessageCracker
{
public:
  void run();

    FIX::SessionID cur_sess;
    int64_t clordid{0};

private:
  void onCreate( const FIX::SessionID& ) {}
  void onLogon( const FIX::SessionID& sessionID );
  void onLogout( const FIX::SessionID& sessionID );
  void toAdmin( FIX::Message&, const FIX::SessionID& ) {}
  void toApp( FIX::Message&, const FIX::SessionID& )
    THROW_DECL( FIX::DoNotSend );
  void fromAdmin( const FIX::Message& message, const FIX::SessionID& )
    THROW_DECL( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon ) {}
  void fromApp( const FIX::Message& message, const FIX::SessionID& sessionID )
    THROW_DECL( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType );

  void onMessage( const FIX40::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX40::OrderCancelReject&, const FIX::SessionID& );
  void onMessage( const FIX41::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX41::OrderCancelReject&, const FIX::SessionID& );
  void onMessage( const FIX42::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX42::OrderCancelReject&, const FIX::SessionID& );
  void onMessage( const FIX43::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX43::OrderCancelReject&, const FIX::SessionID& );
  void onMessage( const FIX44::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX44::OrderCancelReject&, const FIX::SessionID& );
  void onMessage( const FIX50::ExecutionReport&, const FIX::SessionID& );
  void onMessage( const FIX50::OrderCancelReject&, const FIX::SessionID& );

  void testPingPong();
  void testFlow();
  void queryEnterOrder();
  void queryCancelOrder();
  void queryReplaceOrder();
  void queryMarketDataRequest();

  FIX40::NewOrderSingle queryNewOrderSingle40();
  FIX41::NewOrderSingle queryNewOrderSingle41();
  FIX42::NewOrderSingle queryNewOrderSingle42();
  FIX43::NewOrderSingle queryNewOrderSingle43();
  FIX44::NewOrderSingle queryNewOrderSingle44();
  FIX50::NewOrderSingle queryNewOrderSingle50();
  FIX40::OrderCancelRequest queryOrderCancelRequest40();
  FIX41::OrderCancelRequest queryOrderCancelRequest41();
  FIX42::OrderCancelRequest queryOrderCancelRequest42();
  FIX43::OrderCancelRequest queryOrderCancelRequest43();
  FIX44::OrderCancelRequest queryOrderCancelRequest44();
  FIX50::OrderCancelRequest queryOrderCancelRequest50();
  FIX40::OrderCancelReplaceRequest queryCancelReplaceRequest40();
  FIX41::OrderCancelReplaceRequest queryCancelReplaceRequest41();
  FIX42::OrderCancelReplaceRequest queryCancelReplaceRequest42();
  FIX43::OrderCancelReplaceRequest queryCancelReplaceRequest43();
  FIX44::OrderCancelReplaceRequest queryCancelReplaceRequest44();
  FIX50::OrderCancelReplaceRequest queryCancelReplaceRequest50();
  FIX43::MarketDataRequest queryMarketDataRequest43();
  FIX44::MarketDataRequest queryMarketDataRequest44();
  FIX50::MarketDataRequest queryMarketDataRequest50();

  void queryHeader( FIX::Header& header );
  char queryAction();
  int queryVersion();
  bool queryConfirm( const std::string& query );

  FIX::SenderCompID querySenderCompID();
  FIX::TargetCompID queryTargetCompID();
  FIX::TargetSubID queryTargetSubID();
  FIX::ClOrdID queryClOrdID();
  FIX::OrigClOrdID queryOrigClOrdID();
  FIX::Symbol querySymbol();
  FIX::Side querySide();
  FIX::OrderQty queryOrderQty();
  FIX::OrdType queryOrdType();
  FIX::Price queryPrice();
  FIX::StopPx queryStopPx();
  FIX::TimeInForce queryTimeInForce();
};

#endif
