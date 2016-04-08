
#pragma once


#include <cppexpose/typed/AbstractTyped.h>
#include <cppexpose/reflection/Named.h>


namespace cppexpose
{


/**
*  @brief
*    Base class for reflection-enabled objects
*/
class CPPEXPOSE_API PropertyGroup : public AbstractTyped, public Named
{
public:
    /**
    *  @brief
    *    Constructor
    *
    *  @param[in] name
    *    Name
    */
    PropertyGroup(const std::string & name);

    /**
    *  @brief
    *    Destructor
    */
    virtual ~PropertyGroup();

    // Virtual AbstractTyped interface
    virtual AbstractTyped * clone() const;
    virtual const std::type_info & type() const;
    virtual std::string typeName() const;
    virtual bool isReadOnly() const;
    virtual bool isComposite() const;
    virtual size_t numSubValues() const;
    virtual AbstractTyped * subValue(size_t i);
    virtual bool isEnum() const override;
    virtual bool isArray() const override;
    virtual bool isVariant() const override;
    virtual bool isString() const override;
    virtual bool isBool() const override;
    virtual bool isNumber() const override;
    virtual bool isIntegral() const override;
    virtual bool isSignedIntegral() const override;
    virtual bool isUnsignedIntegral() const override;
    virtual bool isFloatingPoint() const override;
    virtual Variant toVariant() const override;
    virtual bool fromVariant(const Variant & value) override;
    virtual std::string toString() const override;
    virtual bool fromString(const std::string & value) override;
    virtual bool toBool() const override;
    virtual bool fromBool(bool value) override;
    virtual long long toLongLong() const override;
    virtual bool fromLongLong(long long value) override;
    virtual unsigned long long toULongLong() const override;
    virtual bool fromULongLong(unsigned long long value) override;
    virtual double toDouble() const override;
    virtual bool fromDouble(double value) override;
};


} // namespace cppexpose