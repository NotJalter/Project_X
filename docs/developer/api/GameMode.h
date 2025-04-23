/*! \file GameMode.h
    \brief Заголовочный файл класса GameMode
*/

/*! \class AGameMode
    \brief Основной класс игровой логики

    Отвечает за:
    - Управление игровым процессом
    - Инициализацию игровых объектов
    - Обработку игровых событий
    - Управление игровым состоянием
*/
class AGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    /*! \brief Конструктор по умолчанию
        Инициализирует игровой режим
    */
    AGameMode();

    /*! \brief Вызывается при начале игры
        Инициализирует игровые объекты и настраивает начальное состояние
    */
    virtual void BeginPlay() override;

    /*! \brief Вызывается каждый кадр
        \param DeltaTime Время, прошедшее с предыдущего кадра
        Обновляет игровое состояние и обрабатывает события
    */
    virtual void Tick(float DeltaTime) override;

    /*! \brief Обрабатывает завершение уровня
        \param bSuccess Успешно ли завершен уровень
        Сохраняет прогресс и загружает следующий уровень
    */
    void HandleLevelComplete(bool bSuccess);

    /*! \brief Обрабатывает смерть игрока
        Перезагружает текущий уровень или возвращает к последней точке сохранения
    */
    void HandlePlayerDeath();

protected:
    /*! \brief Менеджер уровней
        Управляет загрузкой и выгрузкой уровней
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
    ALevelManager* LevelManager;

    /*! \brief Система сохранения
        Управляет сохранением и загрузкой игрового прогресса
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
    USaveSystem* SaveSystem;

    /*! \brief Текущее игровое состояние
        Хранит информацию о текущем состоянии игры
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
    FGameState CurrentGameState;

private:
    /*! \brief Инициализирует игровые объекты
        Создает и настраивает необходимые объекты для игры
    */
    void InitializeGameObjects();

    /*! \brief Настраивает игровые правила
        Устанавливает параметры игрового процесса
    */
    void SetupGameRules();
}; 