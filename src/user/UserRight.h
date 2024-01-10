#pragma once
class UserRight {
private:
	bool _canAddImage;
	bool _canRemoveImage;
	bool _canSaveImage;

public:
	UserRight();
	UserRight(const bool &, const bool&, const bool&);

	bool getAddImageRight() const;
	bool getRemoveImageRight() const;
	bool getSaveImageRight() const;
};