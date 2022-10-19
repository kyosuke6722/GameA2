#include "Field03.h"

Field03::Field03():Base(eType_Field) {
	m_img = COPY_RESOURCE("Background03", CImage);
}

void Field03::Draw(){
	m_img.Draw();
}