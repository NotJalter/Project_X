/*! \file PlayerCharacter.h
    \brief Заголовочный файл класса PlayerCharacter
*/

/*! \class PlayerCharacter
    \brief Основной класс игрока

    Класс PlayerCharacter представляет собой главного персонажа игры.
    Отвечает за управление персонажем, взаимодействие с окружением и применение механики крюка.
*/
class PlayerCharacter : public ACharacter
{
public:
    /*! \brief Конструктор по умолчанию
        \param ObjectInitializer Инициализатор объекта
    */
    PlayerCharacter(const FObjectInitializer& ObjectInitializer);

    /*! \brief Вызывается при начале игры
        Инициализирует компоненты персонажа и настраивает начальные параметры
    */
    virtual void BeginPlay() override;

    /*! \brief Вызывается каждый кадр
        \param DeltaTime Время, прошедшее с предыдущего кадра
        Обрабатывает ввод игрока и обновляет состояние персонажа
    */
    virtual void Tick(float DeltaTime) override;

    /*! \brief Обрабатывает ввод для движения вперед/назад
        \param Value Значение ввода (-1.0 до 1.0)
    */
    void MoveForward(float Value);

    /*! \brief Обрабатывает ввод для движения вправо/влево
        \param Value Значение ввода (-1.0 до 1.0)
    */
    void MoveRight(float Value);

    /*! \brief Активирует механику крюка
        Запускает крюк в направлении прицеливания
    */
    void ActivateGrapplingHook();

    /*! \brief Деактивирует механику крюка
        Отключает крюк и возвращает персонажа в нормальное состояние
    */
    void DeactivateGrapplingHook();

protected:
    /*! \brief Компонент камеры
        Отвечает за вид от первого лица
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    UCameraComponent* CameraComponent;

    /*! \brief Компонент крюка
        Реализует механику гравитационного крюка
    */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay)
    UGrapplingHookComponent* GrapplingHookComponent;

    /*! \brief Скорость движения персонажа
        Определяет базовую скорость передвижения
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
    float MovementSpeed;
}; 