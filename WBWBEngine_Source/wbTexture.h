#pragma once
#include "wbResource.h"

namespace wb
{
    class Texture  : public Resource
    {
    public:
        enum class eTextureType
        {
            Bmp,
            Png,
            None,
        };

        Texture();
        ~Texture();

        virtual HRESULT Load(const std::wstring& path) override;

        UINT GetWidth() { return mWidth; }
        UINT GetHeight() { return mHeight; }
        HDC GetHdc() { return mHdc; }
        eTextureType GetTextureType() { return mType; }
        Gdiplus::Image* GetImage() { return mImage; }
    private:
        UINT mWidth;
        UINT mHeight;
        HDC mHdc;
        HBITMAP mBitmap;

        eTextureType mType;
        Gdiplus::Image* mImage;
    };

}