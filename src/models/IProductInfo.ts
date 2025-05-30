import type { IProductCharacter } from './IProductCharacter'

export interface IProductInfo {
    id: number
    name: string
    data: IProductCharacter
    description: string
    filenamePath: string
    webviewPath?: string
}
