/**
 * @file QF_Image.h
 * @brief Image Manipulation API
 * @copyright This software is the confidential and proprietary information of Suprema AI Inc. ("Confidential Information").  You shall not disclose such Confidential Information and shall use it only in accordance with the terms of the license agreement you entered into with Suprema AI Inc.
 */

#ifndef __QFM_SDK_IMAGE_H__
#define __QFM_SDK_IMAGE_H__

/**
 * @brief Structure of QFImage
 * @par Example
 * @code
// QFImage can be used to read the last scanned face image like below.
QFImage image;
memset(&image, 0, sizeof(QFImage));
QF_RET_CODE result = QF_ReadImage( &image );
QF_ReleaseImage( &image );

// If you use the pointer of QFImage, you can use it like below.
QFImage *image = (QFImage*)malloc(sizeof(QFImage));
memset(image, 0, sizeof(QFImage));
QF_RET_CODE result = QF_ReadImage( image );
QF_ReleaseImage( image );
free(image);
 * @endcode
 * @note In the example, the image’s memory is automatically allocated after calling the \ref QF_ReadImage(). So release the memory using \ref QF_ReleaseImage() if you don’t use the image on the program anymore. Also, if you use the pointer of QFImage, you should handle the memory allocation and release by yourself. If you use the pointer of QFImage, you should release the memory using free() after calling \ref QF_ReleaseImage().
 */
typedef struct{
    /*! length of the image data */
    UINT32 length;
    /*! pointer of the image data */
    BYTE *data;
}QFImage;

#endif
