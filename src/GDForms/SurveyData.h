//
// Created by eugene on 10.11.24.
//

#ifndef SURVEYDATA_H
#define SURVEYDATA_H
#define USE_MATH_DEFINES

#include <chrono>
#include <qlist.h>
#include <cmath>
#include <ctime>
#include <cstring>
/// Таблица используется для рассчета CRC.
unsigned short crc16tab[256] =
        {
            0x0000, 0xc0c1, 0xc181, 0x0140, 0xc301, 0x03c0, 0x0280, 0xc241,
            0xc601, 0x06c0, 0x0780, 0xc741, 0x0500, 0xc5c1, 0xc481, 0x0440,
            0xcc01, 0x0cc0, 0x0d80, 0xcd41, 0x0f00, 0xcfc1, 0xce81, 0x0e40,
            0x0a00, 0xcac1, 0xcb81, 0x0b40, 0xc901, 0x09c0, 0x0880, 0xc841,
            0xd801, 0x18c0, 0x1980, 0xd941, 0x1b00, 0xdbc1, 0xda81, 0x1a40,
            0x1e00, 0xdec1, 0xdf81, 0x1f40, 0xdd01, 0x1dc0, 0x1c80, 0xdc41,
            0x1400, 0xd4c1, 0xd581, 0x1540, 0xd701, 0x17c0, 0x1680, 0xd641,
            0xd201, 0x12c0, 0x1380, 0xd341, 0x1100, 0xd1c1, 0xd081, 0x1040,
            0xf001, 0x30c0, 0x3180, 0xf141, 0x3300, 0xf3c1, 0xf281, 0x3240,
            0x3600, 0xf6c1, 0xf781, 0x3740, 0xf501, 0x35c0, 0x3480, 0xf441,
            0x3c00, 0xfcc1, 0xfd81, 0x3d40, 0xff01, 0x3fc0, 0x3e80, 0xfe41,
            0xfa01, 0x3ac0, 0x3b80, 0xfb41, 0x3900, 0xf9c1, 0xf881, 0x3840,
            0x2800, 0xe8c1, 0xe981, 0x2940, 0xeb01, 0x2bc0, 0x2a80, 0xea41,
            0xee01, 0x2ec0, 0x2f80, 0xef41, 0x2d00, 0xedc1, 0xec81, 0x2c40,
            0xe401, 0x24c0, 0x2580, 0xe541, 0x2700, 0xe7c1, 0xe681, 0x2640,
            0x2200, 0xe2c1, 0xe381, 0x2340, 0xe101, 0x21c0, 0x2080, 0xe041,
            0xa001, 0x60c0, 0x6180, 0xa141, 0x6300, 0xa3c1, 0xa281, 0x6240,
            0x6600, 0xa6c1, 0xa781, 0x6740, 0xa501, 0x65c0, 0x6480, 0xa441,
            0x6c00, 0xacc1, 0xad81, 0x6d40, 0xaf01, 0x6fc0, 0x6e80, 0xae41,
            0xaa01, 0x6ac0, 0x6b80, 0xab41, 0x6900, 0xa9c1, 0xa881, 0x6840,
            0x7800, 0xb8c1, 0xb981, 0x7940, 0xbb01, 0x7bc0, 0x7a80, 0xba41,
            0xbe01, 0x7ec0, 0x7f80, 0xbf41, 0x7d00, 0xbdc1, 0xbc81, 0x7c40,
            0xb401, 0x74c0, 0x7580, 0xb541, 0x7700, 0xb7c1, 0xb681, 0x7640,
            0x7200, 0xb2c1, 0xb381, 0x7340, 0xb101, 0x71c0, 0x7080, 0xb041,
            0x5000, 0x90c1, 0x9181, 0x5140, 0x9301, 0x53c0, 0x5280, 0x9241,
            0x9601, 0x56c0, 0x5780, 0x9741, 0x5500, 0x95c1, 0x9481, 0x5440,
            0x9c01, 0x5cc0, 0x5d80, 0x9d41, 0x5f00, 0x9fc1, 0x9e81, 0x5e40,
            0x5a00, 0x9ac1, 0x9b81, 0x5b40, 0x9901, 0x59c0, 0x5880, 0x9841,
            0x8801, 0x48c0, 0x4980, 0x8941, 0x4b00, 0x8bc1, 0x8a81, 0x4a40,
            0x4e00, 0x8ec1, 0x8f81, 0x4f40, 0x8d01, 0x4dc0, 0x4c80, 0x8c41,
            0x4400, 0x84c1, 0x8581, 0x4540, 0x8701, 0x47c0, 0x4680, 0x8641,
            0x8201, 0x42c0, 0x4380, 0x8341, 0x4100, 0x81c1, 0x8081, 0x4040
        };

class Package0x80
{
    unsigned char* preparedData = new unsigned char[63];

    /// @brief Основные расчеты CRC байтов.
    unsigned short CalcCRC16( unsigned short CRC, unsigned char b) {
        CRC = (CRC >> 8) ^ crc16tab[(CRC ^ b) & 0xff];
        return CRC;
    }

    /// @brief Проверка целостности пакета. Два последние два байта CRC пакета 0х80 рассчитываются прибором при отправке.
    /// Использую аналогичную логику, функция считает эти байты в программе.
    /// Возвращает true если CRC совпадают и пакет цел, если CRC не совпадает и пакет поврежден, возвращает false
    bool CheckCRC(unsigned char* praparedData) {
            unsigned short CRC = 0x0000;
        for(int i = 1; i < 19; i++) {
            CRC = CalcCRC16(CRC, praparedData[i]);
        }
        if (preparedData[20] == static_cast<unsigned char>(CRC >> 8) && preparedData[19] == static_cast<unsigned char>(CRC)) {
            qDebug() << "CheckCRC passed";
            return true;
        }
        qDebug() << "CheckCRC Error\nExpected:";
        qDebug() << hex << preparedData[19] << preparedData[20];
        qDebug() << "Calculated CRC :";
        qDebug() << hex << static_cast<unsigned char>(CRC >> 8) << static_cast<unsigned char>(CRC);
        return  false;
    }

    public:
    double hx;
    double gx;
    double hy;
    double gy;
    double hz;
    double gz;
    double temp;
    double volt;

    /// @brief Проверку CRC целостности пакета лучше перенести в приём данных, чтобы избежать Null при создании экземпляра
    /// @param rawData сырой пакет данных

    explicit Package0x80(QByteArray *rawData)
    {
        /// Парсинг пакета для выкидывания дублирующих 0х06 байтов.
        /// Начало пакета всегда 0х06 0х01 0х02, конец 0х06 0х04. Чтобы случайно не нати конец или начало внутри данных,
        /// все 0х06 байты в нем дублируются. Например последовательность 0х06 0х06 0х04 не означает 0х06 + конец пакета,
        /// они означают, что в данных тоже есть 0х06 0х04. Здесь мы проходим по пакету и отбрасываем эти защитные дублирования 0х06.
        char* data = rawData->data();
        bool dropped06 = false;
        bool startFound = false;
        int preparedDataIndex = 0;
        while(*data) {
            if (!startFound) {
                if (static_cast<unsigned char>(*data) == 0x80) {
                    //Начало пакета. Сигнал к старту заполнения массива отфильтрованных данных.
                    startFound = true;
                }
                data++;
                continue;
            }
            if (static_cast<unsigned char>(*data) == 0x06 && preparedDataIndex > 0)
                //Нашли байт 0х06 и массив отфильтрованных данных не пустой.
            {
                if(preparedData[preparedDataIndex - 1] == 0x06 && dropped06 == false) {
                    //В отфильтрованном массиве последний байт 0х06 и 0х06 не выкинут в предыдущем цикле (для случая 0х06 0х06 0х06 0х06).
                    dropped06 = true;
                    data++; //пропускаем повторный 0х06 байт
                    continue;
                }
            }
            preparedData[preparedDataIndex] = static_cast<unsigned char>(*data); //заносим байт в массив
            dropped06 = false; //указываем что дропа не было в этом цикле 
            preparedDataIndex++;
            data++;
        }

        qDebug() << "Размер пакета:" << preparedDataIndex;
        qDebug() << "Первые 4 байта пакета:" << preparedData[0] << preparedData[1] << preparedData[2] << preparedData[3];

        CheckCRC(preparedData);

        //Восстанавливаем данные: склеиваем два байта -> Читаем ushort как int16 -> переводим в double -> переносим плавающую точку в правильное место
        this->hx = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[3]) << 8 | preparedData[4])) / 10000;
        this->gx = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[5]) << 8| preparedData[6])) / 10000;
        this->hy = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[7]) << 8 | preparedData[8])) / 10000;
        this->gy = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[9]) << 8 | preparedData[10])) / 10000;
        this->hz = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[11]) << 8 | preparedData[12])) / 10000;
        this->gz = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[13]) << 8 | preparedData[14])) / 10000;
        this->temp = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[15]) << 8 | preparedData[16])) / 100;
        this->volt = static_cast<double>(static_cast<int16_t>(static_cast<unsigned short>(preparedData[17]) << 8 | preparedData[18])) / 100;
    }
};

class SurveyShot
{
    public:
        int no;
        int branch = 0;
        int excluded = 0;
        int length;
        int depth;
        double hx;
        double gx;
        double hy;
        double gy;
        double hz;
        double gz;
        double hv;
        double gv;
        double temp;
        double volt;
        double az;
        double dip;
        double dtrack;
        double u_d;
        double l_r;
        double tlf;
        double tlfOffset;
        double desiredAzimuth;
        double declination;
        time_t dateTime;
        int sensorSerial;
        int batterySerial;
        int surveyCount;
        float batterymAh;
        float batteryHoursUsed;
        float batterymAhUsed;
        float signalStrength;
        double northing;
        double easting;
        double verticalDisplacement;
        double gammaTlf1;
        float gammaCps1;
        double gammaTlf2;
        float gammaCps2;
        double magneticTlf;
        double magneticTlfOffset;
        int version;
        int warning;

        /// @brief Класс будет создаваться как конструктор из разных пкетов. Парметры соответственно изменятся на эти пакеты.
        SurveyShot(Package0x80 *package0_x80, double declination = 0, double tlfOffset = 0, double magneticTlfOffset = 0)
        {
            hx = package0_x80->hx;
            gx = package0_x80->gx;
            hy = package0_x80->hy;
            gy = package0_x80->gy;
            hz = package0_x80->hz;
            gz = package0_x80->gz;
            temp = package0_x80->temp;
            volt = package0_x80->volt;

            hv = sqrt(pow(hx, 2) + pow(hy, 2) + pow(hz, 2));
            gv = sqrt(pow(gx, 2) + pow(gy, 2) + pow(gz, 2));

            double Phi = atan2(gy , gz);
            double sinPhi = sin(Phi);
            double cosPhi = cos(Phi);

            double MagPhi = atan(hy / hz);

            double my = hy*cosPhi - hz*sinPhi;
            double mhz = hy*sinPhi + hz*cosPhi;
            double mgz = gy*sinPhi + gz*cosPhi;

            double The = atan2(-gx , mgz);
            double sinThe = sin(The);
            double cosThe = cos(The);
            double mx = hx*cosThe + mhz*sinThe;
            double mz = -hx * sinThe + mhz * cosThe;

            double Psi = atan2(-my , mx);

            double PhiDeg = Phi * 180 / M_PI;
            PhiDeg += tlfOffset;
            if (PhiDeg < 0) PhiDeg = 360 + PhiDeg;
            if (PhiDeg > 360) PhiDeg = PhiDeg - 360;
            tlf = PhiDeg + tlfOffset;

            double MagPhiDeg = MagPhi * 180 / M_PI;
            MagPhiDeg += magneticTlfOffset;
            if (MagPhiDeg < 0) MagPhiDeg = 360 + MagPhiDeg;
            if (MagPhiDeg > 360) MagPhiDeg = MagPhiDeg - 360;
            magneticTlf = MagPhiDeg;

            double TheDeg = The * 180 / M_PI;
            dip = TheDeg;

            double PsiDeg = Psi * 180 / M_PI;
            PsiDeg += declination;
            if (PsiDeg < 0) PsiDeg = 360 + PsiDeg;
            if (PsiDeg > 360) PsiDeg = PsiDeg - 360;
            az = PsiDeg;
        }
};

class SurveyData
{
public:
    QList<SurveyShot> SurveyList;
    double desiredAzimuth;
    double tlfOffset;
    double declination;

    ///@brief  Контейнер замеров. Создается в двух случаях: 1 при создании новой скважины, 2 открытие из сохраненного файла.
    ///При открытии из файла всегда применяется конструктор с одним замером.
    ///Конструктор с двумя замерами только при созданииновой скважины и только если оператор указал глубину отличную от нуля.
    ///Если при создании новой скважины глубина первого замара указана 0, соответственно применяется конструктор с одним замером.
    ///@param firstSurvey указатель на первый замер. Расчетные параметры этого замера по умолчанию ставятся в 0. Делаем новый при создании скважины, либо читаем первый при открытии файла.
    ///@param desiredAzimuth проектный азимут, указывается оператором в форме при создании скважины или берется из последнего замера при открытии файла.
    ///@param tlfOffset смещение тулфейса, указывается оператором в форме при создании скважины или берется из последнего замера при открытии файла.
    ///@param declination величина магнитного склонения, указывается оператором в форме при создании скважины или берется из последнего замера при открытии файла.
    SurveyData(SurveyShot *firstSurvey, double desiredAzimuth, double tlfOffset, double declination)
    {
        this->desiredAzimuth = desiredAzimuth;
        this->tlfOffset = tlfOffset;
        this-> declination = declination;

        firstSurvey->no = 0;
        firstSurvey->length = 0;
        firstSurvey->depth = 0;
        firstSurvey->desiredAzimuth = desiredAzimuth;
        firstSurvey->declination = declination;
        firstSurvey->tlfOffset = tlfOffset;
        firstSurvey->dtrack = 0;
        firstSurvey->u_d = 0;
        firstSurvey->l_r = 0;
        firstSurvey->easting = 0;
        firstSurvey->northing = 0;
        firstSurvey->verticalDisplacement = 0;
        SurveyList = {*firstSurvey};
    }
    ///@overload
    ///@param firstSurvey указатель на первый замер. Расчетные параметры этого замера по умолчанию ставятся в 0.
    ///@param secondSurvey указатель на второй замер. Инструментальные данные повторяют firstSurvey, но остальные уже расчитываются.
    ///@param depthOfSecondSurvey глубина, на которой произведено измерение. Указывается оператором в форме при создании скважины.
    ///@param desiredAzimuth проектный азимут, указывается оператором в форме при создании скважины.
    ///@param tlfOffset смещение тулфейса, указывается оператором в форме при создании скважины.
    ///@param declination величина магнитного склонения, указывается оператором в форме при создании скважины.
    SurveyData(SurveyShot *firstSurvey, SurveyShot *secondSurvey, int depthOfSecondSurvey, double desiredAzimuth, double tlfOffset, double declination)
    {
        this->desiredAzimuth = desiredAzimuth;
        this->tlfOffset = tlfOffset;
        this-> declination = declination;

        firstSurvey->no = 0;
        firstSurvey->length = 0;
        firstSurvey->depth = 0;
        firstSurvey->desiredAzimuth = desiredAzimuth;
        firstSurvey->declination = declination;
        firstSurvey->tlfOffset = tlfOffset;
        firstSurvey->dtrack = 0;
        firstSurvey->u_d = 0;
        firstSurvey->l_r = 0;
        firstSurvey->easting = 0;
        firstSurvey->northing = 0;
        firstSurvey->verticalDisplacement = 0;
        SurveyList = {*firstSurvey};
        AddSurveyShot(secondSurvey, depthOfSecondSurvey);
    }

    ///@brief Добавление в список замеров нового и расчет его тригонометрии
    ///@param surveyToAdd замер, который нужно добавить
    ///@param interval расстояние от предыдущего замера, указанное машинистом
    void AddSurveyShot(SurveyShot *surveyToAdd, int interval)
    {
        SurveyShot newSurvey = *surveyToAdd;
        SurveyShot previousSurvey = *PreviousSurvey(surveyToAdd);

        newSurvey.no = SurveyList.count();
        newSurvey.length = interval;
        newSurvey.depth = previousSurvey.depth + interval;
        newSurvey.desiredAzimuth = desiredAzimuth;
        newSurvey.declination = declination;
        newSurvey.tlfOffset = tlfOffset;
        newSurvey.dtrack = newSurvey.length / 2.0 * (cos(M_PI * (newSurvey.az - desiredAzimuth) / 180) * cos(M_PI * newSurvey.dip / 180) +
            (cos(M_PI * (previousSurvey.az - desiredAzimuth) / 180)) * cos(M_PI * previousSurvey.dip / 180)) + previousSurvey.dtrack; ;
        newSurvey.u_d = newSurvey.length / 2.0 * (sin(M_PI * newSurvey.dip / 180) + sin(M_PI * previousSurvey.dip / 180)) + previousSurvey.u_d;
        newSurvey.l_r = newSurvey.length / 2.0 * (sin(M_PI * (newSurvey.az - desiredAzimuth) / 180) * cos(M_PI * newSurvey.dip / 180) +
            (sin(M_PI * (previousSurvey.az - desiredAzimuth) / 180)) * cos(M_PI * previousSurvey.dip / 180)) + previousSurvey.l_r;
        newSurvey.easting = newSurvey.length / 2.0 * (sin(M_PI * newSurvey.az / 180) * cos(M_PI * newSurvey.dip / 180) +
            (sin(M_PI * previousSurvey.az / 180)) * cos(M_PI * previousSurvey.dip / 180)) + previousSurvey.easting;
        newSurvey.northing = newSurvey.length / 2.0 * (cos(M_PI * newSurvey.az / 180) * cos(M_PI * newSurvey.dip / 180) +
            (cos(M_PI * previousSurvey.az / 180)) * cos(M_PI * previousSurvey.dip / 180)) + previousSurvey.northing;
        newSurvey.verticalDisplacement = newSurvey.length / 2.0 * (sin(M_PI * newSurvey.dip / 180) + sin(M_PI * previousSurvey.dip / 180)) + previousSurvey.verticalDisplacement;

        SurveyList.push_back(newSurvey);
    }

    ///@brief Поиск предыдущего замера в списке от которого рассчитываются данные текущего
    ///@param currentSurvey текущий замер, данные которого необходимо рассчитать
    ///@return Объект класса SurveyShot
    SurveyShot* PreviousSurvey(SurveyShot* currentSurvey)
    {
        return &SurveyList[PreviousSurveyIndex((currentSurvey->no))];
    }
    ///@overload PreviousSurvey()
    ///@param  currentIndex индекс текущего замера, данные которого необходимо рассчитать
    SurveyShot* PreviousSurvey(int currentIndex)
    {
        return &SurveyList[PreviousSurveyIndex(currentIndex)];
    }

    ///@brief Поиск индекса предыдущего замера в списке от которого рассчитываются данные текущего
    ///@param currentSurvey текущий замер, данные которого необходимо рассчитать
    ///@return Индекс предыдущего замера
    int PreviousSurveyIndex(SurveyShot* currentSurvey)
    {
        return PreviousSurveyIndex(currentSurvey->no);
    }
    ///@overload PreviousSurveyIndex()
    ///@param  currentIndex индекс текущего замера, данные которого необходимо рассчитать
    int PreviousSurveyIndex(int currentIndex)
    {
        for (int j = currentIndex - 1; j >= 0; j--)
        {
            if (SurveyList[j].excluded == 0 && SurveyList[currentIndex].branch == SurveyList[j].branch)
            {
                return j;
            }
        }
        for (int j = currentIndex - 1; j >= 0; j--)
        {
            if (SurveyList[j].excluded == 0)
            {
                return j;
            }
        }
        return 0;
    }

    ///recalculate surveys in case of change parameters

    void RecalculateSurveys (double target_azimuth)
    {
        //do maths
    }

    ///return max depth
    int CurrentDepth()
    {
        if (!SurveyList.isEmpty())
        {
            return SurveyList[SurveyList.size()-1].depth;
        }
        return 0;
    }

    void CreateBranch()
    {

    }
};
#endif SURVEYDATA_H
