
#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <cppexpose/type/Type.h>
#include <cppexpose/type/ConcreteType.h>
#include <cppexpose/value/InternalValue.h>
#include <cppexpose/value/ExternalValue.h>
#include <cppexpose/variant/Variant.h>


using namespace cppexpose;


class Test
{
public:
    Test()
    : m_number(0)
    {
    }

    ~Test()
    {
    }

    int number() const
    {
        return m_number;
    }

    void setNumber(int number)
    {
        m_number = number;
    }

protected:
    int m_number;
};

enum Weather
{
    Rainy,
    Cloudy,
    Sunny
};

int intValue;

int getInt()
{
    return intValue;
}

void setInt(const int & value)
{
    intValue = value;
}

void printType(const std::string & name, const AbstractValueContainer & value)
{
    std::cout << name << " is " << value.type().typeName() << std::endl;

    std::cout << std::endl;
}

void printTypeInfo(const std::string & name, Type & type)
{
    std::cout << "typeof(" << name << "): " << type.typeName() << std::endl;
    std::cout << name << " is const:    " << (type.isConst() ? "true" : "false") << std::endl;
    std::cout << name << " is boolean:  " << (type.isBoolean() ? "true" : "false") << std::endl;
    std::cout << name << " is number:   " << (type.isNumber() ? "true" : "false") << std::endl;
    std::cout << name << " is integral: " << (type.isIntegral() ? "true" : "false") << std::endl;
    std::cout << name << " is unsigned: " << (type.isUnsigned() ? "true" : "false") << std::endl;
    std::cout << name << " is float:    " << (type.isFloatingPoint() ? "true" : "false") << std::endl;
    std::cout << name << " is string:   " << (type.isString() ? "true" : "false") << std::endl;
    std::cout << name << " is array:    " << (type.isArray() ? "true" : "false") << std::endl;
    if (type.isArray()) {
        std::cout << "- dynamic: " << (type.isDynamicArray() ? "true" : "false") << std::endl;
        std::cout << "- elementType: " << type.elementType().typeName() << std::endl;
    }
    std::cout << name << " is map:      " << (type.isMap() ? "true" : "false") << std::endl;

    std::cout << std::endl;
}

void printValue(const std::string & name, AbstractValueContainer & value)
{
    std::cout << name << "(int) = " << value.value<int>() << std::endl;
    std::cout << name << "(float) = " << value.value<float>() << std::endl;
    std::cout << name << "(string) = " << value.toString() << std::endl;
    std::cout << name << "(longlong) = " << value.toLongLong() << std::endl;
    std::cout << name << "(ulonglong) = " << value.toULongLong() << std::endl;
    std::cout << name << "(double) = " << value.toDouble() << std::endl;
    std::cout << name << "(bool) = " << value.toBool() << std::endl;

    std::cout << std::endl;
}

int main(int, char * [])
{
    // Types
    ConcreteType<bool> boolType;
    ConcreteType<int> intType;
    ConcreteType<unsigned int> uintType;
    ConcreteType<long> longType;
    ConcreteType<unsigned long> ulongType;
    ConcreteType<float> floatType;
    ConcreteType<double> doubleType;
    ConcreteType<std::string> stringType;
    ConcreteType<int[3]> arrayType1;
    ConcreteType<std::array<bool, 3>> arrayType2;
    ConcreteType<std::vector<float>> arrayType3;
    ConcreteType<std::map<std::string, float>> mapType;
    ConcreteType<Test> testType;
    ConcreteType<Weather> weatherType;

    std::cout << "int: "           << intType.minimumValue()    << " .. " << intType.maximumValue()    << std::endl;
    std::cout << "unsigned int: "  << uintType.minimumValue()   << " .. " << uintType.maximumValue()   << std::endl;
    std::cout << "long: "          << longType.minimumValue()   << " .. " << longType.maximumValue()   << std::endl;
    std::cout << "unsigned long: " << ulongType.minimumValue()  << " .. " << ulongType.maximumValue()  << std::endl;
    std::cout << "float: "         << floatType.minimumValue()  << " .. " << floatType.maximumValue()  << std::endl;
    std::cout << "double: "        << doubleType.minimumValue() << " .. " << doubleType.maximumValue() << std::endl;
    std::cout << std::endl;

    weatherType.setNamedValues({
        { "Rainy", Rainy },
        { "Cloudy", Cloudy },
        { "Sunny", Sunny }
    });

    printTypeInfo("bool",               boolType);
    printTypeInfo("int",                intType);
    printTypeInfo("uint",               uintType);
    printTypeInfo("long",               longType);
    printTypeInfo("ulong",              ulongType);
    printTypeInfo("float",              floatType);
    printTypeInfo("double",             doubleType);
    printTypeInfo("string",             stringType);
    printTypeInfo("int_array[3]",       arrayType1);
    printTypeInfo("array<bool, 3>",     arrayType2);
    printTypeInfo("vector<float>",      arrayType3);
    printTypeInfo("map<string, float>", mapType);
    printTypeInfo("test",               testType);
    printTypeInfo("weather",            weatherType);

    // Values
    InternalValue<int> intValue;
    intValue.setValue(23);
    printValue("int", intValue);
    printType("int", intValue);

    InternalValue<Weather> weatherValue;
    weatherValue.fromString("Sunny");
    printValue("weather", weatherValue);
    printType("weather", weatherValue);

    // Managed values
    ExternalValue<int> value(getInt, setInt);

    // Exit
    return 0;
}
