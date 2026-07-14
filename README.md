# Geometry Playground

## Project Goal
외부 라이브러리에 의존하지 않고 
**컴퓨터 비전(Computer Vision), 3D Geometry, Camera Calibration, 3D Reconstruction, Photometric Stereo** 등을 직접 구현하는 것을 목표로 하는 프로젝트. <br>
<br>
최종 목표

- Math &Geometry Library (Vector, Matrix, Quaternion, Rotation, Transform, Plane, Ray ...)
- Camera Model
- Calibration Toolkit
- 3D Reconstruction Pipeline
- Photometric Stereo

---

# Current Progress

## Project Structure

```
GeometryPlayground
│
├── Geometry.Core
│   ├── Math
│   │   ├── DoubleVector
│   │   ├── DoubleMatrix
│   │   └── Utils
│   │
│   └── Geometry
│       ├── Rotation
│       └── Transform
│
└── Geometry.Demo
```

---

# Implemented

## Math

### Vec2d

Implemented

- Constructors
- operator[]
- operator+
- operator-
- Scalar multiplication
- Scalar division
- Dot Product
- Norm
- Normalize

---

### Vec3d

Implemented

- Constructors
- operator[]
- operator+
- operator-
- Scalar multiplication
- Scalar division
- Dot Product
- Cross Product
- Norm
- Normalize

---

### Mat2d

Implemented

- Constructors
- operator()
- operator[]
- Matrix Addition
- Matrix Subtraction
- Scalar Multiplication
- Scalar Division
- Matrix Multiplication
- Transpose
- Determinant
- Inverse
- Identity
- IsApprox


---

### Mat3d

Implemented

- Constructors
- operator()
- operator[]
- Matrix Addition
- Matrix Subtraction
- Scalar Multiplication
- Scalar Division
- Matrix Multiplication
- Matrix × Vector
- Transpose
- Determinant
- Cofactor Matrix
- Adjugate Matrix
- Inverse
- Identity
- IsApprox

Inverse implemented through

```
Determinant
      ↓
Cofactor Matrix
      ↓
Adjugate Matrix
      ↓
Inverse
```

---

### Mat4d

Implemented

- Constructors
- operator()
- operator[]
- Matrix Addition
- Matrix Subtraction
- Scalar Multiplication
- Scalar Division
- Matrix Multiplication
- Transpose
- Determinant
- Cofactor Matrix
- Adjugate Matrix
- Inverse
- Identity
- IsApprox

---

# Geometry

## Rotation

Implemented

### Rodrigues Formula

```
R = I + sinθ K + (1-cosθ)K²
```

where

```
K =
[  0   -z    y ]
[  z    0   -x ]
[ -y    x    0 ]
```

Implemented

- Rodrigues()
- Skew()
- IsRotationMatrix()

Verification

```
RᵀR = I
det(R)=1
```

---

## Transform

Implemented

Transformation Matrix

```
[ R11 R12 R13 tx ]
[ R21 R22 R23 ty ]
[ R31 R32 R33 tz ]
[  0   0   0  1 ]
```

Implemented

- Identity
- Translate
- Rotate
- FromRotationTranslation
- Inverse

Inverse implemented as

```
T⁻¹

[ Rᵀ  -Rᵀt ]
[ 0      1 ]
```

---

# Demo

Implemented demo program for

- Rodrigues Rotation
- Rotation Matrix Verification
- Transformation Matrix
- Inverse Transformation
- Identity Verification

---

# Verified

Verified

- Matrix Multiplication
- Determinant
- Inverse
- Rodrigues Rotation
- Rotation Matrix Validation
- Transformation Matrix
- Inverse Transformation

using

```
T × T⁻¹ = I
```

and

```
RᵀR = I
```

---

# Next Step

Planned implementation order

```
Camera
    ↓
Calibration Toolkit
    ↓
3D Reconstruction Pipeline
    ↓
Photometric Stereo
```
