#include <stdint.h>
#include "umdbase.h"
#include "cartfactory.h"
#include "genesis.h"
#include "sms.h"
#include "generic.h"
#include "noopcart.h"




CartFactory::CartFactory()
{
    carts[CartFactory::UNDEFINED]   = new noopcart();
    carts[CartFactory::COLECO] = new GenericCart();
    carts[CartFactory::GEN]    = new GenericCart();
    carts[CartFactory::SMS]    = new sms();
    carts[CartFactory::PCE]    = new GenericCart();
    carts[CartFactory::TG16]   = new GenericCart();
    carts[CartFactory::SNES]   = new GenericCart();
    carts[CartFactory::SNESLO] = new GenericCart();
}

CartFactory::~CartFactory()
{
    for (int i=0; i < CARTS_LEN; i++)
    {
	delete carts[i];
    }
}


umdbase* CartFactory::getCart(CartFactory::Mode mode)
{
    if (mode < CARTS_LEN && mode > CartFactory::UNDEFINED)
    {
        return carts[mode];
    }
    return carts[CartFactory::UNDEFINED];
}

CartFactory::Mode CartFactory::getMaxCartMode()
{
    return static_cast<Mode>(CARTS_LEN);
}

