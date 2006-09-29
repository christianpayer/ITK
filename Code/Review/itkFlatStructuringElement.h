#ifndef __itkFlatStructuringElement_h
#define __itkFlatStructuringElement_h

#include "itkNeighborhood.h"
#include "itkSize.h"
#include "itkOffset.h"
#include <vector>
#include "itkVector.h"

namespace itk {

/** \class FlatStructuringElement
* \brief A class to support a variety of flat structuring elements, 
* including versions created by decomposition of lines.
**/

template<class TImage, unsigned int VDimension>
class ITK_EXPORT FlatStructuringElement : 
  public Neighborhood <bool, VDimension>
{
public:
  /** Standard class typedefs. */
  typedef FlatStructuringElement< TImage, VDimension > Self;
  typedef Neighborhood<bool, VDimension> Superclass;

  /** External support for pixel type. */
  typedef typename Superclass::PixelType PixelType;

  /** Typedefs related to the Image */
  typedef TImage                         ImageType;
  typedef typename ImageType::Pointer    ImagePointer;
  typedef typename ImageType::PixelType  ImagePixelType;

  /** Typedefs for specific images */
  typedef Image< unsigned char, VDimension >        UnsignedCharImageType;
  typedef typename UnsignedCharImageType::Pointer   UnsignedCharImagePointer;
  
  /** Iterator typedef support. Note the naming is intentional, i.e.,
  * ::iterator and ::const_iterator, because the allocator may be a
  * vnl object or other type, which uses this form. */
  typedef typename Superclass::Iterator       Iterator;
  typedef typename Superclass::ConstIterator ConstIterator;
  
  /** Size and value typedef support. */
  typedef typename Superclass::SizeType      SizeType;
  typedef typename Superclass::SizeValueType SizeValueType;
  
  /** Radius typedef support. */
  typedef typename Superclass::RadiusType RadiusType;

  /** External slice iterator type typedef support. */
  typedef typename Superclass::SliceIteratorType SliceIteratorType;
  
  /** External support for dimensionality. */
  itkStaticConstMacro(NeighborhoodDimension, unsigned int, VDimension);

  /** Default destructor. */
  virtual ~FlatStructuringElement() {}

  /** Default consructor. */
  FlatStructuringElement() {}

  /** Various constructors */

  static Self Box(RadiusType radius);
  
  static Self Ball(RadiusType radius);
  
  static Self FromImage( 
                 const ImageType * image,
                 ImagePixelType foreground = 
                     NumericTraits< ImagePixelType >::max() );

  static Self FromImageUC( 
                  const UnsignedCharImageType * image,
                  unsigned char foreground = 
                     NumericTraits< unsigned char >::max() 
                  );

  /** return an itk::Image from the structuring element. Background defaults to
   * NumericTraits< PixelType >::Zero and foreground to
   * NumericTraits< PixelType >::max()
   */
  ImagePointer GetImage( 
      ImagePixelType foreground = NumericTraits< ImagePixelType >::max(),
      ImagePixelType background = NumericTraits< ImagePixelType >::Zero );

  /** return an itk::Image< unsigned char, VDimension > from the structuring element
   * This method is there to be used from wrappers. From C++, you should prefer
   * the GetImage() method.
   */
   UnsignedCharImagePointer GetImageUC( unsigned char foreground, 
                                        unsigned char background );
   
  /** return an itk::Image< unsigned char, VDimension > from the structuring element
   * This method is there to be used from wrappers. From C++, you should prefer
   * the GetImage() method.
   */
   UnsignedCharImagePointer GetImageUC();
   
   
protected:


private:


};

} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFlatStructuringElement.txx"
#endif



#endif
