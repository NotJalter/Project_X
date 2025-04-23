/*! \file GrapplingHookComponent.h
    \brief Заголовочный файл компонента GrapplingHook
*/

/*! \class UGrapplingHookComponent
    \brief Компонент, реализующий механику гравитационного крюка

    Компонент отвечает за реализацию механики крюка, включая:
    - Запуск крюка
    - Расчет траектории
    - Притягивание к объектам
    - Управление состоянием крюка
*/
class UGrapplingHookComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /*! \brief Конструктор по умолчанию
        Инициализирует компонент с базовыми параметрами
    */
    UGrapplingHookComponent();

    /*! \brief Активирует крюк
        \param StartLocation Начальная позиция крюка
        \param Direction Направление запуска крюка
        \return true, если крюк успешно активирован
    */
    bool ActivateHook(const FVector& StartLocation, const FVector& Direction);

    /*! \brief Деактивирует крюк
        Прекращает действие крюка и возвращает его в исходное положение
    */
    void DeactivateHook();

    /*! \brief Обновляет состояние крюка
        \param DeltaTime Время, прошедшее с предыдущего кадра
        Вычисляет новую позицию крюка и обрабатывает столкновения
    */
    void UpdateHook(float DeltaTime);

    /*! \brief Возвращает текущую позицию крюка
        \return Вектор позиции крюка
    */
    FVector GetHookLocation() const;

    /*! \brief Проверяет, активен ли крюк
        \return true, если крюк активен
    */
    bool IsHookActive() const;

protected:
    /*! \brief Максимальная дальность крюка
        Определяет максимальное расстояние, на которое может быть запущен крюк
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hook Settings")
    float MaxHookDistance;

    /*! \brief Скорость крюка
        Определяет скорость движения крюка
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hook Settings")
    float HookSpeed;

    /*! \brief Сила притяжения
        Определяет силу, с которой крюк притягивает персонажа
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hook Settings")
    float PullForce;

private:
    /*! \brief Текущая позиция крюка
        Хранит текущие координаты крюка в мире
    */
    FVector CurrentHookLocation;

    /*! \brief Флаг активности крюка
        Указывает, активен ли крюк в данный момент
    */
    bool bIsHookActive;

    /*! \brief Целевая позиция крюка
        Хранит позицию, к которой движется крюк
    */
    FVector TargetLocation;
}; 