#ifndef FIX43_SECURITYTYPES_H
#define FIX43_SECURITYTYPES_H

#include "Message.h"

namespace FIX43
{

  class SecurityTypes : public Message
  {
  public:
    SecurityTypes() : Message(MsgType()) {}
    SecurityTypes(const Message& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("w"); }

    SecurityTypes(
      const FIX::SecurityReqID& aSecurityReqID,
      const FIX::SecurityResponseID& aSecurityResponseID,
      const FIX::SecurityResponseType& aSecurityResponseType )
    : Message(MsgType())
    {
      set(aSecurityReqID);
      set(aSecurityResponseID);
      set(aSecurityResponseType);
    }

    FIELD_SET(*this, FIX::SecurityReqID);
    FIELD_SET(*this, FIX::SecurityResponseID);
    FIELD_SET(*this, FIX::SecurityResponseType);
    FIELD_SET(*this, FIX::TotalNumSecurityTypes);
    FIELD_SET(*this, FIX::Text);
    FIELD_SET(*this, FIX::EncodedTextLen);
    FIELD_SET(*this, FIX::EncodedText);
    FIELD_SET(*this, FIX::TradingSessionID);
    FIELD_SET(*this, FIX::TradingSessionSubID);
    FIELD_SET(*this, FIX::SubscriptionRequestType);
    FIELD_SET(*this, FIX::NoSecurityTypes);
    class NoSecurityTypes: public FIX::Group
    {
    public:
    NoSecurityTypes() : FIX::Group(558,167,FIX::message_order(167,460,461,0)) {}
      FIELD_SET(*this, FIX::SecurityType);
      FIELD_SET(*this, FIX::Product);
      FIELD_SET(*this, FIX::CFICode);
    };
  };

}

#endif
