#include <string>
using namespace std;

class Metadata {
public:
	Metadata(string file, string image, int month, int day, int year, double size, string author, double width, double height, string aperture, double exposure, int ISO_Value, bool flash);
	 string getFileName() const;
	 string getImageType() const;
	 int getMonth() const;
	 int getDay() const;
	 int getYear() const;
	 double getSize() const;
	 string getAuthor() const;
	 double getWidth() const;
	 double getHeight() const;
	 string getApertureSize() const;
	 double getExposureTime() const;
	 int getISOValue() const;
	 bool isFlashEnabled() const;

	void setFileName(string file);
	void setImageType(string image);
	void setDateCreated(int month, int day, int year);
	void setSize(double size);
	void setAuthor(string author);
	void setImageDimensions(double width, double height);
	void setApertureSize(string aperture);
	void setExposureTime(double exposure);
	void setISOValue(int ISO_Value);
	void setFlashEnabled(bool flash);
private:
	string fileName;
	string imageType;
	int m, d, y;
	double s;
	string authorName;
	double w, h;
	string apertureSize;
	double exposureTime;
	int iso;
	bool f;
};

ostream& operator << (ostream& out, const Metadata& metadata);
