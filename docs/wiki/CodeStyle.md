# Стиль кода HookGame

## Общие правила

### Именование
- **Классы**: PascalCase
  ```cpp
  class APlayerCharacter
  class UGameManager
  class FGameState
  ```

- **Переменные**: camelCase
  ```cpp
  float health;
  FVector playerLocation;
  TArray<AActor*> actors;
  ```

- **Константы**: UPPER_CASE
  ```cpp
  const int MAX_HEALTH = 100;
  const FString DEFAULT_NAME = "Player";
  ```

- **Методы**: PascalCase
  ```cpp
  void Jump();
  void HandleDamage(float Amount);
  bool IsAlive() const;
  ```

### Отступы и пробелы
- Используйте 4 пробела для отступов
- Не используйте табуляцию
- Добавляйте пробел после запятых
- Добавляйте пробелы вокруг операторов

```cpp
// Правильно
if (health > 0)
{
    Jump();
    Attack();
}

// Неправильно
if(health>0){
    Jump();
    Attack();
}
```

## Структура файлов

### Заголовочные файлы (.h)
1. Защита от повторного включения
2. Включение необходимых заголовков
3. Объявление класса
4. Публичные члены
5. Защищенные члены
6. Приватные члены

```cpp
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class HOOKGAME_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APlayerCharacter();

protected:
    virtual void BeginPlay() override;

private:
    float Health;
};
```

### Файлы реализации (.cpp)
1. Включение заголовка
2. Включение других заголовков
3. Реализация методов

```cpp
#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
    Health = 100.0f;
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}
```

## Комментарии

### Документация
- Используйте Doxygen стиль
- Документируйте публичные методы
- Документируйте сложные приватные методы
- Обновляйте документацию при изменениях

```cpp
/**
 * @brief Класс игрока
 * 
 * Отвечает за управление персонажем и взаимодействие с игровым миром.
 * 
 * @see ACharacter
 */
class APlayerCharacter : public ACharacter
{
    /**
     * @brief Обрабатывает получение урона
     * 
     * @param Amount Количество урона
     * @return true, если персонаж выжил
     */
    bool TakeDamage(float Amount);
};
```

### Встроенные комментарии
- Используйте для объяснения сложной логики
- Не комментируйте очевидное
- Пишите комментарии на русском языке
- Обновляйте комментарии при изменениях

```cpp
// Проверяем, может ли персонаж прыгнуть
if (CanJump())
{
    // Применяем силу прыжка
    LaunchCharacter(FVector(0, 0, JumpForce), false, true);
}
```

## Макросы Unreal Engine

### UPROPERTY
- Используйте категории
- Добавляйте описания
- Указывайте метаданные

```cpp
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Stats",
    meta = (DisplayName = "Health", Tooltip = "Current health of the player"))
float Health;
```

### UFUNCTION
- Указывайте категории
- Добавляйте описания
- Используйте соответствующие флаги

```cpp
UFUNCTION(BlueprintCallable, Category = "Player|Actions",
    meta = (DisplayName = "Jump", Tooltip = "Makes the player jump"))
void Jump();
```

## Обработка ошибок

### Проверки
- Используйте check() для фатальных ошибок
- Используйте ensure() для предупреждений
- Логируйте важные события

```cpp
void APlayerCharacter::TakeDamage(float Amount)
{
    check(Amount >= 0.0f);
    
    if (Health <= 0.0f)
    {
        UE_LOG(LogGame, Warning, TEXT("Player is already dead"));
        return;
    }
    
    Health -= Amount;
    UE_LOG(LogGame, Log, TEXT("Player took %f damage"), Amount);
}
```

### Исключения
- Избегайте исключений в игровом коде
- Используйте возвращаемые значения
- Обрабатывайте ошибки явно

```cpp
bool APlayerCharacter::UseItem(UItem* Item)
{
    if (!Item)
    {
        UE_LOG(LogGame, Error, TEXT("Invalid item"));
        return false;
    }
    
    // Использование предмета
    return true;
}
``` 