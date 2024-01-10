#include "UserRight.h"

UserRight::UserRight() 
{
	this->_canAddImage = false;
	this->_canRemoveImage = false;
	this->_canSaveImage = false;
}

UserRight::UserRight(const bool &canAddImage, const bool &canRemoveImage, const bool &canSaveImage)
{
	this->_canAddImage = canAddImage;
	this->_canRemoveImage = canRemoveImage;
	this->_canSaveImage = canSaveImage;
}

bool UserRight::getAddImageRight() const
{
	return this->_canAddImage;
}

bool UserRight::getRemoveImageRight() const
{
	return this->_canRemoveImage;
}

bool UserRight::getSaveImageRight() const
{
	return this->_canSaveImage;
}
