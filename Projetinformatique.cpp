#include "Projetinformatique.h"
#include <sstream>
#include "database/Database.h"

Projetinformatique::Projetinformatique(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // Appeler la fonction de test lors de la cr�ation de l'objet Projetinformatique
    //testGetImages(database);

}

Projetinformatique::~Projetinformatique()
{}
std::stringstream c;
/***
void Projetinformatique:: testGetImages( Database database) {
    // Cr�ez quelques images pour la base de donn�es
    ImageDescriptor descriptor1(1, "C:/Users/allao/OneDrive/Desktop/projet Info/test_project/b1.jpg", "title1", "source1", "author1", 1);
    Image image1(descriptor1);

    ImageDescriptor descriptor2(2, "C:/Users/allao/OneDrive/Desktop/projet Info/test_project/pomme.webp", "title2", "source2", "author2", 2);
    Image image2(descriptor2);

    // Ajoutez les images � la base de donn�es
    database.addImage(image1);
    database.addImage(image2);

    // Utilisez la fonction getImages pour obtenir la liste des images
    std::vector<Image> images = database.getImages();

    // Vous pouvez afficher ou utiliser les images comme bon vous semble ici
    // par exemple, afficher les noms des images dans la console
    for (const auto& img : images) {
        // c << img.getImageDescriptor().getTitle()<<std::endl ;
         img.show();

    }
}

***/

void Projetinformatique::on_pushButton_clicked()
{
    
    ui.plainTextEdit->setPlainText(QString::fromStdString(c.str()));
    ImageDescriptor descriptor3(3, "C:/Users/allao/OneDrive/Desktop/projet Info/test_project/image1.png", "title3", "source2", "author2", 3);
    Image image3(descriptor3);
    image3.show();
    /*
        database.addImage(image3);
        std::vector<Image> images = database.getImages();
        for (const auto& img : images) 
        {
            c << img.getImageDescriptor().getTitle() << std::endl;
            img.show();
        }
    */

    cv::Mat image_filtre;
    image3.applyMedianFilter(image3.getImage(), image_filtre, 3);
    image3.setImage(image_filtre);
    image3.show();

    ImageDescriptor descriptor4(3, "C:/Users/allao/OneDrive/Desktop/projet Info/test_project/erosion.png", "title3", "source2", "author2", 4);
    Image image4(descriptor4);
    image4.show();

    cv::Mat imageErode;
    image4.applyErosionFilter(image4.getImage(), imageErode,2,3);
    image4.setImage(imageErode);
    image4.show();

    ImageDescriptor descriptor5(3, "C:/Users/allao/OneDrive/Desktop/projet Info/test_project/erosion.png", "title3", "source2", "author2", 4);
    Image image5(descriptor5);
    image5.show();

    cv::Mat imageDilation;
    image5.applyDilationFilter(image5.getImage(), imageDilation, 2, 3);
    image5.setImage(imageDilation);
    image5.show();

}

