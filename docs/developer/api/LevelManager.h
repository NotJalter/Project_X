/*! \file LevelManager.h
    \brief Заголовочный файл класса LevelManager
*/

/*! \class ALevelManager
    \brief Класс управления уровнями игры

    Отвечает за:
    - Загрузку и выгрузку уровней
    - Управление прогрессом игрока
    - Генерацию уровней
    - Сохранение состояния уровней
*/
class ALevelManager : public AActor
{
    GENERATED_BODY()

public:
    /*! \brief Конструктор по умолчанию
        Инициализирует менеджер уровней
    */
    ALevelManager();

    /*! \brief Загружает указанный уровень
        \param LevelName Имя уровня для загрузки
        \return true, если уровень успешно загружен
    */
    bool LoadLevel(const FName& LevelName);

    /*! \brief Выгружает текущий уровень
        Сохраняет состояние уровня перед выгрузкой
    */
    void UnloadCurrentLevel();

    /*! \brief Сохраняет прогресс уровня
        \param LevelName Имя уровня
        \param Progress Данные прогресса
    */
    void SaveLevelProgress(const FName& LevelName, const FLevelProgress& Progress);

    /*! \brief Загружает прогресс уровня
        \param LevelName Имя уровня
        \return Данные прогресса уровня
    */
    FLevelProgress LoadLevelProgress(const FName& LevelName);

    /*! \brief Генерирует новый уровень
        \param LevelType Тип генерируемого уровня
        \return true, если уровень успешно сгенерирован
    */
    bool GenerateLevel(ELevelType LevelType);

protected:
    /*! \brief Список доступных уровней
        Хранит информацию о всех уровнях игры
    */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Levels")
    TArray<FLevelInfo> AvailableLevels;

    /*! \brief Текущий загруженный уровень
        Хранит информацию о текущем уровне
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
    FLevelInfo CurrentLevel;

    /*! \brief Система сохранения
        Отвечает за сохранение и загрузку прогресса
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Save System")
    USaveSystem* SaveSystem;

private:
    /*! \brief Загружает конфигурацию уровней
        Загружает настройки уровней из конфигурационных файлов
    */
    void LoadLevelConfig();

    /*! \brief Инициализирует уровень
        \param LevelInfo Информация об уровне
        Настраивает начальное состояние уровня
    */
    void InitializeLevel(const FLevelInfo& LevelInfo);
}; 