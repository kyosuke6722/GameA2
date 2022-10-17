#include "Field01.h"




Field01::Field01()
	:Base(eType_Field)
{
	m_img = COPY_RESOURCE("background", CImage);

}

void Field01::Draw()
{
	m_img.SetSize(1280, 720);
	m_img.Draw();

}
