/*! \file SaveSystem.h
    \brief Заголовочный файл класса SaveSystem
*/

/*! \class USaveSystem
    \brief Класс системы сохранения игры

    Отвечает за:
    - Сохранение и загрузку игрового прогресса
    - Управление сейвами
    - Сериализацию игровых данных
*/
class USaveSystem : public UObject
{
    GENERATED_BODY()

public:
    /*! \brief Конструктор по умолчанию
        Инициализирует систему сохранения
    */
    USaveSystem();

    /*! \brief Сохраняет игровой прогресс
        \param SaveSlot Имя слота сохранения
        \param SaveData Данные для сохранения
        \return true, если сохранение успешно
    */
    bool SaveGame(const FString& SaveSlot, const FSaveGameData& SaveData);

    /*! \brief Загружает игровой прогресс
        \param SaveSlot Имя слота сохранения
        \return Данные сохранения
    */
    FSaveGameData LoadGame(const FString& SaveSlot);

    /*! \brief Удаляет сохранение
        \param SaveSlot Имя слота сохранения
        \return true, если удаление успешно
    */
    bool DeleteSave(const FString& SaveSlot);

    /*! \brief Проверяет существование сохранения
        \param SaveSlot Имя слота сохранения
        \return true, если сохранение существует
    */
    bool DoesSaveExist(const FString& SaveSlot);

protected:
    /*! \brief Путь к директории сохранений
        Хранит путь к папке с сохранениями
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Save System")
    FString SaveDirectory;

    /*! \brief Расширение файлов сохранения
        Определяет формат файлов сохранения
    */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Save System")
    FString SaveFileExtension;

private:
    /*! \brief Получает полный путь к файлу сохранения
        \param SaveSlot Имя слота сохранения
        \return Полный путь к файлу
    */
    FString GetSaveFilePath(const FString& SaveSlot);

    /*! \brief Сериализует данные сохранения
        \param SaveData Данные для сериализации
        \return Сериализованные данные
    */
    TArray<uint8> SerializeSaveData(const FSaveGameData& SaveData);

    /*! \brief Десериализует данные сохранения
        \param SerializedData Сериализованные данные
        \return Десериализованные данные
    */
    FSaveGameData DeserializeSaveData(const TArray<uint8>& SerializedData);
}; 