#ifndef _ICONFIGURATION_H_
#define _ICONFIGURATION_H_

class IComportement;


class IConfiguration
{
public:
    virtual ~IConfiguration() {}

    virtual IComportement *tirerComportement() const = 0;
};

#endif