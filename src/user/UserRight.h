#ifndef USERRIGHTS_H
#define USERRIGHTS_H

class UserRight {
	private:
		bool _canAddImage;
		bool _canRemoveImage;
		bool _canSaveImage;

	public:
		UserRight();
		UserRight(const bool &, const bool &, const bool &);

		bool getAddImageRight() const;
		bool getRemoveImageRight() const;
		bool getSaveImageRight() const;
};

#endif //USERRIGHTS_H
